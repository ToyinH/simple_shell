#include "simple_shell.h"
/**
 * custom_exit - exit function handling the argument
 * @argve: array of strings
 *
 */
void custom_exit(char **argve)
{
	if (argve[1] != NULL)
	{
		exit(_atoi(argve[1]));
	}
	/** free(str) **/
	free(argve);
	exit(EXIT_SUCCESS);
}
