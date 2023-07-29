#include "simple_shell.h"

/**
 * _setenv - function to handle setenv
 * @argv: array of pointers
 *
 * Return: return 0 on success
 */
extern char **environ;
int _setenv2(char **argv, char **env)
{
	const char *name;
	char **env_ptr;
	const char *new_value;
	int result;
	(void)env;

	env_ptr = environ;
	name = argv[1];
	new_value = "Holberton";
	result = setenv(name, new_value, 1);
	if (result != 0)
	{
		free(argv);
		perror("setenv error");
		return (1);
	}
	
	while (*env_ptr != NULL)
	{
		_printf(*env_ptr);
		_printf("\n");
		env_ptr++;
	}
	return (0);
}
