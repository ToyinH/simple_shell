#include "simple_shell.h"
/**
 * fork_exec - function that fork and execute function
 * @argv: argument vector to track tokens
 * @env: environment
 * @av: argument vector
 */
void fork_exec(char **argv, char **env, char **av)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		free_argv(argv);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			printf("%s: No such file or directory\n", av[0]);
	}
	else
		wait(&status);
}
