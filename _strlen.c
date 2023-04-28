#include "shell.h"

/**
 * _strlen - find length of string
 * @string: string
 *
 * Return: length
 */

int _strlen(const char *string)
{
	int i;

	if (!string)
		return (0);

	for (i = 0; string[i] != '\0'; i++)
	{
	}

	return (i);
}

/**
 * _strcat - concatnate strings
 * @dest: destination string
 * @src: source string
 *
 * Return: the result
 */

char *_strcat(char *dest, const char *src)
{
	char *result = dest;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest++ = *src++;
	}

	*dest = '\0';

	return (result);
}
