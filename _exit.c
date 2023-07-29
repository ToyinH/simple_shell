#include "simple_shell.h"
/**
 * custom_exit - exit function handling the argument
 * @argve: array of strings
 *
 */
void custom_exit(char **argve)
{
	int exit_status;
	char *err;

	if (argve[1] != NULL)
	{
		exit_status = _atoi(argve[1]);
		if (exit_status == 0)
		{
			err = "./hsh: 1: exit: Illegal number: ";
			write(STDERR_FILENO, err, _strlen(err));
			write(STDERR_FILENO, argve[1], _strlen(argve[1]));
			write(STDERR_FILENO, "\n", 1);
			free(argve);
			exit(2);
		}
		else if (exit_status < 0)
		{
			err = "./hsh: 1: exit: Illegal number: -98\n";
			write(STDERR_FILENO, err, _strlen(err));
			free(argve);
			exit(2);
		}
		free(argve);
		exit(exit_status);
	}
	/** free(str) **/
	free(argve);
	exit(EXIT_SUCCESS);
}
