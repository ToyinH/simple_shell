#include "simple_shell.h"
/**
 * custom_strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: return 0 if equal, else return the difference between the strings
 * actually it returns the difference between the mismatched character
 */
int custom_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
