#include "shell.h"

/**
 * sigint_stop - stop ctrl c
 * @sig_num: signal
 */

void sigint_stop(int sig_num)
{
	(void)sig_num;

	write(1, "\n", 1);
	write(1, "($) ", 4);
}

/**
 * main - execution stage
 *
 * Return: 0 on success
 */

int main(void)
{
	char *input = NULL;
	size_t size = 1024;
	ssize_t outpt;
	char **argv = NULL;

	signal(SIGINT, sigint_stop);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);

		fflush(stdout);
		outpt = getline(&input, &size, stdin);
		if (outpt == -1)
		{
			free(input);
			exit(1);
		}

		if (*input == '\n' || *input == '\0')
			continue;

		argv = srt_input(input);
		argv[0] = get_path(argv[0]);
		execpid(argv[0], argv, environ);

		free(input);
		 _free(argv);
		input = NULL;
	}

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
	int parent;

	if (!command)
		exit(-1);

	pid = fork();

	if (pid == -1)
	{
		perror("busted");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(command, argv, env) == -1)
		{
			_free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&parent);
		fflush(stdout);
	}

	return (0);
}
