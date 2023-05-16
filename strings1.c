#include "shell.h"

/**
 * srt_input - sort a string into preferred form i.e tokenized with space as delimeter
 * @str: string
 *
 * Return: string pointer
 */

char **srt_input(char *str)
{
	char **args;
	char *token, *dup_dest;
	int i = 0, c = 0;

	if (!str)
		return (NULL);

	str = rm_nwline(str);/*remove new line character from string cos it causes errors*/
	dup_dest = _strdup(str);
	token = strtok(str, " ");
	while (token != NULL)
	{
		c++;/*get number of strings we want to make*/
		token = strtok(NULL, " ");
	}

	args = (char **)malloc(sizeof(char *) * (c + 1));/*+1 for NULL*/
	if (args == NULL)
		return (NULL);

	token = strtok(dup_dest, " ");
	while (token != NULL)
	{
		args[i] = _strdup(token);/*assign strings to this double pointer array, so we have an array of strings i.e ls -l*/
		token = strtok(NULL, " ");/*continue tokenizing, its kinda like a recurssion*/
		i++;
	}

	args[i] = NULL;

	free(dup_dest);

	return (args);
}

/**
 * _strdup - duplicate a string
 * @str: string to duplicate
 *
 * Return: string
 */

char *_strdup(const char *str)
{
	int len;
	char *new_string;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;
	new_string = malloc(len);

	if (new_string != NULL)
	{
		_strcpy(new_string, str);

		return (new_string);
	}

	return (NULL);
}

/**
 * _strcpy - copy string to a pointer
 * @dest: destination
 * @src: source
 *
 * Return: destination
 */

char *_strcpy(char *dest, const char *src)
{
	char *ptr;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	ptr = dest;

	while (*src)
	{
		*ptr++ = *src++;
	}

	*ptr = '\0';

	return (dest);
}

/**
 * rm_nwline - removes newline char
 * @str: string
 *
 * Return: string with no newline
 */

char *rm_nwline(char *str)
{
	char *sub = str;

	if (str == NULL)
		return (NULL);

	sub = strtok(sub, "\n");
	return (sub);
}
