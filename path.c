#include "shell.h"

/**
 * path_maker - get the path of program i.e the /bin/ for ls to be /bin/ls
 * @cmd: command
 *
 * Return: path
 */

char *path_maker(char *cmd)
{
	char *path, *path_dup, *path_tok, *file_path;
	struct stat str;

	if (cmd == NULL)
		return (NULL);

	if (stat(cmd, &str) == 0)
		return (cmd);

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
	char *file_path;
	int len, i;

	if (path_tok == NULL || cmd == NULL)
		return (NULL);

	len = _strlen(path_tok) + _strlen(cmd) + 2;
	file_path = malloc(sizeof(char) * len);

	if (!file_path)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		file_path[i] = 0;
	}

	file_path[len - 1] = '\0';

	file_path = _strcpy(file_path, path_tok);
	file_path = _strcat(file_path, "/");
	file_path = _strcat(file_path, cmd);

	return (file_path);
}
