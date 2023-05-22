#include "shell.h"

/**
 * error_print - print errors
 * @file: name of our shell
 * @cmd: command inputed
 * @count: programme count
 */

void error_print(char *file, char *cmd, int count)
{
	struct stat st;
	char _count = count + '0';

	if (access(cmd, F_OK) != 0)
	{
		write(STDERR_FILENO, file, _strlen(file));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, &_count, 1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd, _strlen(cmd));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "not found\n", 10);
	}
	else if ((stat(cmd, &st) == 0 && S_ISDIR(st.st_mode))
			|| access(cmd, X_OK) != 0)
	{
		write(STDERR_FILENO, file, _strlen(file));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, &_count, 1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd, _strlen(cmd));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "permission denied\n", 18);
	}
	else if (stat(cmd, &st) != 0)
	{
		perror(cmd);
	}
}
