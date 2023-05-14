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
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);

			exit(1);
		}

		if (*input == '\n' || *input == '\0')
			continue;

		argv = srt_input(input);
		execpid(argv, input);

		_free(argv);
	}

	return (0);
}

/**
 * execpid - excecut a command
 * @input: inputed string
 * @argv: the command
 *
 * Return: 0 if success and 1 if not
 *
 */

int execpid(char *argv[], char *input)
{
	pid_t pid;
	int parent;
	char *cmd = NULL, *rubbish = argv[0];

	if (!*argv)
		exit(-1);

	pid = fork();

	if (pid == -1)
	{
		perror("busted");
		return (1);
	}
	else if (pid == 0)
	{
		cmd = get_path(argv[0]);
		if (cmd == NULL)
		{
			perror(rubbish);
			free(input);
			_free(argv);
			exit(EXIT_FAILURE);
		}
		else
			execve(cmd, argv, environ);
	}
	else
	{
		wait(&parent);
		fflush(stdout);
	}

	return (0);
}
