#include "simple_shell.h"
extern char **environ;

/**
 * _setenv - function to handle setenv
 * @argv: array of pointers
 *
 * Return: return 0 on success
 */
int _setenv(char **argv)
{
	const char *name;
	char **env_ptr;
	const char *new_value;
	int result;

	if (custom_strcmp("env", argv[0]) == 0)
	{
		env_ptr = environ;
		while (*env_ptr != NULL)
		{
			_printf(*env_ptr);
			_printf("\n");
			env_ptr++;
		}
		name = argv[2];
		new_value = "Holberton";
		result = setenv(name, new_value, 1);
		if (result != 0)
		{
			free(argv);
			perror("setenv error");
			return (1);
		}
		env_ptr = environ;
		while (*env_ptr != NULL)
		{
			_printf(*env_ptr);
			_printf("\n");
			env_ptr++;
		}

	}
	return (0);
}
