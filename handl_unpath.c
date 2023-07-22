#include "simple_shell.h"
/**
 *
 */

void unpath(char **argv, char **av, char **env, char *str)
{
	if (path_check(argv[0]) == 0)
	{
		fork_exec(argv, env, av);
	}
	else
		printf("%s: No such file or directory\n", av[0]);
	free(str);
	if (argv[1] == NULL)
		free_argv(argv);
	else
		free_argv2(argv);
}
