#include "shell.h"

/**
 * builtin_checker - check for builtins
 * @argv: tokenized strings
 * @status: exit status
 * @input: input from shell
 *
 * Return: 0 to signify env was executed
 */

int builtin_checker(char **argv, int status, char *input)
{
	if (_strcmp(argv[0], "env") == 0)
	{
		while (*environ != NULL)
		{
			write(1, *environ, _strlen(*environ));
			write(1, "\n", 1);

			environ++;
		}

		_free(argv);

		return (0);
	}

	if (_strcmp(argv[0], "exit") == 0)
	{
		if (!argv[1])
		{
			_free(argv);
			free(input);
			exit(status);
		}

		status = _atoi(argv[1]);
		_free(argv);
		free(input);

		exit(status);
	}

	return (1);
}
