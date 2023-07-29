#include "simple_shell.h"
/**
 * custom_exit - exit function handling the argument
 * @argve: array of strings
 *
 */
void custom_exit(char **argve)
{
	int exit_status;

	if (argve[1] != NULL)
	{
		exit_status = _atoi(argve[1]);
		free(argve);
		exit(exit_status);
	}
	/** free(str) **/
	free(argve);
	exit(EXIT_SUCCESS);
}
