#include "simple_shell.h"
/**
 * space_character - function to check if no space character or enter key
 * @strn: string
 *
 * Return: true if it contains character and false if otherwise
 */

bool space_character(char *strn)
{
	int i;

	if (strn[0] == '\0')
	{
		return (false);
	}
	if (strn[0] == '\n')
	{
		return (false);
	}
	for (i = 0; i < len(strn); i++)
	{
		if (strn[i] != ' ')
		{
			return (true);
		}
	}
	return (false);
}

/**
 * len - length of string ending with newline
 * @s: string
 *
 * Return: return string length
 */
int len(char *s)
{
	int j = 0;

	/** while (s[j] != '\n') **/
	while (s[j] != '\0')
	{
		j++;
	}
	return (j);
}
