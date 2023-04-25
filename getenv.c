#include "shell.h"

/**
 * _getenv - get enviroment variable
 * @name: name of first couple of char for variable
 *
 * Return: string
 */

char *_getenv(const char*name)
{
	char **envp = environ;
	char *env_var;

	while (*envp != NULL)
	{
		env_var = *envp;
		
		if (_strcmp(env_var, name) == 0 && env_var[_strlen(name)] == '=')
		{
			return (env_var + _strlen(name) + 1);
		}

		envp++;
	}

	return (NULL);
}
