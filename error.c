#include "shell.h"

/**
 * error_print - print errors
 * @file: name of our shell
 * @cmd: command inputed
 * @count: programme count
 */

void error_print(char *file, char *cmd, size_t count)
{
	struct stat st;

	if (access(cmd, F_OK) != 0)
	{
		write(STDERR_FILENO, file, _strlen(file));
		write(STDERR_FILENO, ": ", 2);
		print_int(count);
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
		print_int(count);
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

/**
 * print_int - print an int as a char
 * @count: integer
 */

void print_int(size_t count)
{
	char num;
	int ary[10];
	int i, j;

	for (i = 0; count > 0; i++)
	{
		ary[i] = count % 10;
		count = count / 10;
	}
	for (j = i - 1; j >= 0; j--)
	{
		num = ary[j] + '0';
		write(STDERR_FILENO, &num, 1);
	}
}
