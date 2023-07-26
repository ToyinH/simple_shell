#include "simple_shell.h"
/**
 * print_env - function that prints enviroment
 * Return: return 0 if successful
 */

int print_env(void)
{
	int i = 0;
	extern char **environ;

	if (environ == NULL)
	{
		perror("environment error");
		return (-1);
	}

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;		
	}
	return 0;
}
