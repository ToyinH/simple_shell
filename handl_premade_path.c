#include "simple_shell.h"
/**
 * premade_path - function to handle premade path command
 * such as /bin/ls
 * @argv: argument vector
 * @av: argument vector from main file
 * @env: enviroment
 * @str: string
 */
void premade_path(char **argv, char **av, char **env, char *str)
{
	if (path_check(argv[0]) == 0)
	{
		fork_exec(argv, env, av);
	}
	else
		printf("%s: No such file or directory\n", av[0]);
	free(str);
	free_argv2(argv);
}