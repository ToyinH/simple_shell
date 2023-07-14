#include "simple_shell.h"
#define MAX 10
/**
 * handl_strtok - function to handle strtok
 * @string: string to tokenize
 * @delimiter: delimiter used to tokenize
 *
 * Return: return array of pointers
 */
char **handl_strtok(char *string, char *delimiter)
{
	int i = 0;
	char **ptr;

	if (string == NULL || delimiter == NULL)
	{
		return (NULL);
	}

	ptr = malloc(sizeof(char *) * MAX);
	if (ptr == NULL)
		return (NULL);

	ptr[i] = strtok(string, " ");
	while(ptr[i] != NULL)
	{
		i++;
		ptr[i] = strtok(NULL, " ");
	}
	return (ptr);
}
