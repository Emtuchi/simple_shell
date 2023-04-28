#include "shell.h"

/**
 * _getenv - get enviroment variable
 * @name: name of first couple of char for variable
 *
 * Return: string
 */

char *_getenv(const char *name)
{
	int row = 0, column = 0;

	while (environ[row])
	{
		while (environ[row][column] && *name)
		{
			if (environ[row][column] != *name || (environ[row][column] == '='))
				break;
			column++, name++;
		}

		if (environ[row][column] == '=' && !*name)
			return ((*(environ + row) + ++column));
		row++;

	}

	return (NULL);
}
