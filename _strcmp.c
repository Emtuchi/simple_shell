#include "shell.h"

/**
 * _strcmp - compare strings
 * @string1: first string
 * @string2: second string
 *
 * Return: 0 if true and -1 if wrong
 */

int _strcmp(const char *string1, const char *string2)
{
	int i, r = 0;

	for (i = 0; string1[i] != '\0' && string2[i] != '\0'; i++)
	{
		if (string1[i] != string2[i])
		{
			r = 1;
		}
	}

	if (string1[i] != string2[i])
	{
		r = 1;
	}

	if (r == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/**
 * srt_input - sort a string into preferred form
 * @str: string
 *
 * Return: string pointer
 */

char **srt_input(char *str)
{
	char **args;
	char *token, *dup_dest;
	int i = 0, c = _strlen(str);

	if (!str)
		return (NULL);

	args = malloc(sizeof(char *) * c);

	if (!args)
		return (NULL);

	str = rm_nwline(str);
	dup_dest = _strdup(str);
	token = strtok(dup_dest, " ");

	while (token != NULL)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, " ");
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
	int i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;
	new_string = malloc(len);

	if (new_string != NULL)
	{
		for (i = 0; i < len - 1; i++)
		{
			new_string[i] = str[i];
		}

		new_string[i] = '\0';
	}

	return (new_string);
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
