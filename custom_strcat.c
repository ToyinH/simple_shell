#include "simple_shell.h"

/**
 * _strcat - this function concatenates two strings
 * @str1: first string
 * @str2: second string
 * Return: the result of the concatenation.
 */

char *_strcat(char *str1, char *str2)
{
	int i = 0, j = 0;

	while (str1[i] != '\0')
		i++;
	for (j = 0; str2[j] != '\0'; j++, i++)
	{
		str1[i] = str2[j];
	}
	str1[i] = '\0';
	return (str1);
}
