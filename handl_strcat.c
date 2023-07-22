#include "simple_shell.h"

/**
 * strcat - this function concatenates two strings
 * @str1: first string
 * @str2: second string
 * @n_byte: bytes to be used
 * Return: the result of the concatenation.
 */

char *strcat(char *str1, char *str2, int n_byte)
{
	char *new_str = str1;
	int i = 0, j = 0;

	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0' && j < n_byte)
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	if (j < n_byte)
		str1[i] = '\0';
	return (new_str);
}
