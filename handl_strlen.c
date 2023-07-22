#include "simple_shell.h"

/**
 * strlen - this function returns the lenght of a string
 * @str: the string whose lenght is being checked
 * Return: the lenght of the string
 */

int strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}
