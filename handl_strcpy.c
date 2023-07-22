#include "simple_shell.h"

/**
 * strcpy - this function copies a string
 * @str_to: the destination to copy to
 * @str1: the string to copy
 * @n_size: size of string being copied
 * Return: copied string
 */

char *strcpy(char *str_to, char *str1, int n_size)
{
	char *str_cpy = str_to;
	int i = 0, j;

	while (i < n_size - 1 && str1[i] != '\0')
	{
		str_to[i] = str1[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			str_to[j] = '\0';
			j++;
		}
	}
	return (str_cpy)
}
