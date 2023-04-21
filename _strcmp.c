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
