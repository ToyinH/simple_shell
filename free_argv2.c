#include "simple_shell.h"
/**
 * free_argv - function to free argv skipping the last string in array
 * @argv: arg vector
 */
void free_argv2(char **argv)
{
	int i = 1;

	if (argv == NULL)
		return;
	while (argv[i] != NULL)
	{
		free(argv[i - 1]);
		i++;
	}
	free(argv);
}

