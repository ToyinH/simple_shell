#include "simple_shell.h"
/**
 * unpath - function handling command with no path e.g ls
 * and command with arg e.g ls -l
 * @argv: argument vector
 * @av: argument vector from main funtion
 * @env: environment
 * @str: string
 */

void unpath(char **argv, char **av, char **env)
{
	if (path_check(argv[0]) == 0)
	{
		fork_exec(argv, env, av);
	}
	else
	{
		_printf(av[0]);
		_printf(": No such file or directory\n");
	}
	/** free(str); **/
	if (argv[1] == NULL)
		free_argv(argv);
	else
		free_argv2(argv);
}
