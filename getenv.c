#include "shell.h"

/**
 * _getenv - get enviroment variable
 * @name: name of first couple of char for variable
 *
 * Return: string
 */

char *_getenv(const char *name)
{
	int i = 0, j = 0;

	while (environ[i])
	{
		while (environ[i][j] && *name)
		{
			if (environ[i][j] != *name || (environ[i][j] == '='))
				break;
			j++, name++;
		}

		if (environ[i][j] == '=' && !*name)
			return ((*(environ + i) + ++j));
		i++;

	}

	return (NULL);
}
