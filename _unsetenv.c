#include "simple_shell.h"

/**
 * _unsetenv - function to handle setenv
 * @argv: array of pointers
 *
 * Return: return 0 on success
 */
extern char **environ;
int _unsetenv(char **argv)
{
	const char *name;
	int result;

	name = argv[1];
	if (name == NULL)
		return (0);
	result = unsetenv(name);
	if (result != 0)
	{
		free(argv);
		perror("setenv error");
		return (1);
	}
	
	return (0);
}
