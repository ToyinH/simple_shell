#include "simple_shell.h"
/**
 * path_check - function that checks path
 * @string: string to check its path
 *
 * Return: return 0 if successful or found.
 */

int path_check(char *string)
{
	char *temp = "/bin/";
	char *new_str, *buffer;
	int i = 0, j;

	while (temp[i] != '\0')
	{
		if (temp[i] != string[i])
		{
			return (1);
		}
		i++;
	}
	buffer = malloc(sizeof(char) * 16);
	if (buffer == NULL)
		return (1);
	j = 0;
	while (string[i] != '\0')
	{
		buffer[j] = string[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
	new_str = file_check(buffer);
	free(buffer);
	if (new_str == NULL)
	{
		return (1);
	}
	else
	{
		free(new_str);
		return (0);
	}
}
