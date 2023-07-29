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
	/**char **env_ptr;**/
	const char *new_value;
	int result;
	(void)env;

	/**env_ptr = environ;**/
	name = argv[1];
	if (name == NULL)
		return (0);
	new_value = argv[2];
	if (new_value == NULL)
		return (0);
	result = setenv(name, new_value, 1);
	if (result != 0)
	{
		free(argv);
		perror("setenv error");
		return (1);
	}
	
	/** while (*env_ptr != NULL)
	{
		_printf(*env_ptr);
		_printf("\n");
		env_ptr++;
	}**/

	return (0);
}
