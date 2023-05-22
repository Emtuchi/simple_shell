#include "shell.h"

/**
 * get_path - get the path of program i.e the /bin/ for ls to be /bin/ls
 * @cmd: command
 *
 * Return: path
 */

char *get_path(char *cmd)
{
	char *path, *path_dup, *path_tok, *file_path;
	struct stat str;

	if (cmd == NULL)
		return (NULL);

	path = _getenv("PATH");
/*search enviroment variable(environ) to get paths, looks kinda like PATH=/usr/local/sbin:/bin:usr/bin/:/bin/:*/

	if (path)
	{
		path_dup = _strdup(path);
		path_tok = strtok(path_dup, ":");
/*split path using :, so split :/bin:usr/bin/: to get just /bin*/

		while (path_tok != NULL)
		{
			file_path = mkpath(path_tok, cmd);
/*add /bin and / to ls to get /bin/ls*/

			if (stat(file_path, &str) == 0)
/*if what we got, in this case /bin/ls is a valid command*/
			{
				free(path_dup);

				return (file_path);
			}
			else
/*incase we got something else i.e /usr/bin/local/ls, which doesnt work*/
			{
				free(file_path);
				path_tok = strtok(NULL, ":");
/*continue moving through the string*/
			}
		}

		free(path_dup);

		if (stat(cmd, &str) == 0)
/*if the command was already executable i.e /bin/ls straight from trminal and we didnt need the above code*/
			return (cmd);


		return (NULL);
/*none of the above worked*/
	}

	return (NULL);
/*nothing in this entire code worked i.e you inputed a rubbish command*/
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
