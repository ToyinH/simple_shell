#include "simple_shell.h"
/**
 * free_argv - function to free argv
 * @argv: arg vector
 */
void free_argv(char **argv)
{
	int i = 0;

	if (argv == NULL)
		return;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

