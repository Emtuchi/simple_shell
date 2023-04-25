#include "shell.h"

/**
 * main - execution stage
 *
 * Return: 0 on success
 */

int main(void)
{
	char *input = NULL;
	size_t size = 0;
	ssize_t outpt;
	char **argv = {NULL};
	char *command;
	char *s = "($) ";
	int len = _strlen(s);

	while (1)
	{
		write(1, s, len);
		fflush(stdout);
		outpt = getline(&input, &size, stdin);

		if (outpt == -1)
		{
			write(1, "\n", 2);
			return (1);
		}

		input = rm_nwline(input);
		argv = srt_input(input);

		command = get_path(argv[0]);
		execpid(command, argv, environ);
	}

	free(input);
	input = NULL;
	size = 0;

	return (0);
}

/**
 * execpid - excecut a command
 * @command: command
 * @argv: the command
 * @env: enviroment variable
 *
 * Return: 0 if success and 1 if not
 *
 */

int execpid(char *command, char *argv[], char **env)
{
	pid_t pid;
	int c;

	pid = fork();

	if (pid == -1)
	{
		perror("busted");
		return (1);
	}
	else if (pid == 0)
	{
		c = execve(command, argv, env);

		if (c == -1)
		{
			perror(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
