#include "simple_shell.h"
/**
 * free_argv2 - function to free argv skipping the last string in array
 * @argv: arg vector
 */
void free_argv2(char **argv)
{
	if (argv == NULL)
		return;
	free(argv[0]);
	free(argv);
}

