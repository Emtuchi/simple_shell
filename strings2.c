#include "shell.h"

/**
 * _strlen - find length of string
 * @string: string
 *
 * Return: length
 */

size_t _strlen(const char *string)
{
	const char *str_startpoint = string;

	while (*string)
	{
		string++;
	}

	return ((size_t) (string - str_startpoint));
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
 * _free - free memory of double pointer
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
		mem_tmp++;
	}

	free(mem);
}

/**
 * _strcmp - compare strings
 * @string1: first string
 * @string2: second string
 *
 * Return: 0 if same
 */

int _strcmp(char *string1, char *string2)
{
	while ((*string1 && *string2) && (*string1 == *string2))
	{
		string1++;
		string2++;
	}

	return (*string1 - *string2);
}
