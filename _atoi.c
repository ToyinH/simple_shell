#include "simple_shell.h"
/**
 * _atoi - custom atoi function
 * @str: string
 *
 * Return: return integer
 *
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
