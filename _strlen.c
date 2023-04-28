#include "shell.h"

/**
 * _strlen - find length of string
 * @string: string
 *
 * Return: length
 */

int _strlen(const char *string)
{
	int i = 0;

	if (!string)
		return (0);

	while (*string++)
	{
		i++;
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

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = '\0';

	return (result);
}

/**
 * _free - free memory
 * @mem: memory to free
 */

void _free(char **mem)
{
	char **mem_tmp;

	if (mem == NULL)
	{
		return;
	}

	mem_tmp = mem;

	while (*mem_tmp != NULL)
	{
		free(*mem_tmp);
		*mem_tmp = NULL;
	}

	free(mem_tmp);
	mem_tmp = NULL;
}
