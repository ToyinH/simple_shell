#include "simple_shell.h"

/**
 * _strcpy - this function copies a string
 * @str_to: the destination to copy to
 * @str1: the string to copy
 * Return: copied string
 */

char *_strcpy(char *str_to, char *str1)
{
	int i = 0, j = 0;

	while (*(str1 + i) != '\0')
	{
		i++;
	}
	for ( ; j < i; j++)
	{
		str_to[j] = str1[j];
	}
	str_to[i] = '\0';
	return (str_to);
}
