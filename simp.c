#include "shell.h"

/**
 * sigint_stop - stop ctrl c
 * @sig_num: there just to avoid errors
 */

void sigint_stop(int sig_num)
{
	(void)sig_num;

	write(1, "\n", 1);
	write(1, "($) ", 4);
}

/**
 * main - execution stage
 * @ac: unused
 * @av: will be used mostly for file_name
 *
 * Return: 0 on success
 */

int main(int ac __attribute__((unused)), char *av[])
{
	char *input = NULL;
	size_t size = 0;
	int count = 0;
	char **argv = NULL;

	signal(SIGINT, sigint_stop);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);

		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);

			exit(1);
		}

		if (*input == '\n' || *input == '\0')
			continue;

		argv = srt_input(input);
		if (!argv || !argv[0])
		{
			_free(argv);
			continue;
		}

		count++;

		execpid(argv, input, av[0], count);

		_free(argv);
	}

	return (0);
}

/**
 * execpid - excecut a command
 * @input: inputed string
 * @argv: the command
 * @programme_name: name of our shell executable
 * @count: how many times programme is running
 *
 * Return: 0 if success
 *
 */

int execpid(char *argv[], char *input, char *programme_name, int count)
{
	pid_t pid;
	int parent;
	char *cmd = NULL;

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
			error_print(programme_name, argv[0], count);
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
