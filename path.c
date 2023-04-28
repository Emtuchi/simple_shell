#include "shell.h"

/**
 * get_path - get the path of program
 * @cmd: command
 *
 * Return: path
 */

char *get_path(char *cmd)
{
	char *path, *path_dup, *path_tok, *file_path;
	struct stat str;

	path = _getenv("PATH");

	if (path)
	{
		path_dup = _strdup(path);
		path_tok = strtok(path_dup, ":");

		while (path_tok != NULL)
		{
			file_path = mkpath(path_tok, cmd);

			if (stat(file_path, &str) == 0)
			{
				free(path_dup);

				return (file_path);
			}
			else
			{
				free(file_path);
				path_tok = strtok(NULL, ":");
			}
		}

		free(path_dup);

		if (stat(cmd, &str) == 0)
		{
			return (cmd);
		}

		return (NULL);
	}

	return (NULL);
}

/**
 * mkpath - construct a path
 * @path_tok: tokenized path
 * @cmd: command
 *
 * Return: path
 */

char *mkpath(char *path_tok, char *cmd)
{
	char *file_path, *result;
	int len, i;

	len = _strlen(path_tok) + _strlen(cmd) + 2;
	file_path = malloc(sizeof(char) * len);

	if (!file_path)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		file_path[i] = 0;
	}

	file_path[len - 1] = '\0';

	result = _strcpy(file_path, path_tok);
	result = _strcat(result, "/");
	result = _strcat(result, cmd);

	return (result);
}
