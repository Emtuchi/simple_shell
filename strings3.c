#include "shell.h"

/**
 * _atoi - convert a string to an integer.
 * @s: the string to be comverted.
 *
 *Return: The integer value of the comverted string.
 */

int _atoi(char *str)
{
	int sign = 1;
	unsigned int num = 0;

	do {

		if (*str == '-')
			sign *= -1;

		else if (*str >= '0' && *str <= '9')
			num = (num * 10) + (*str - '0');

		else if (num > 0)
			break;
	} while (*str++);

	return (num * sign);
}
