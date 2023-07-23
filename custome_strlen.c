#include "simple_shell.h"

/**
 * _strlen - theis function returns the lenght of a string
 * @str: the string to be checked
 * Return: the lenght of the supplied string
 */

int _strlen(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}
