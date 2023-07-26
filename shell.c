#include "simple_shell.h"

/**
 * main - function that creates my shell
 * @ac: argument count;
 * @av: argument vector
 * @env: environment
 *
 * Return: return 0 if successful
 */
int main(int ac, char **av, char **env)
{
	signal(SIGINT, handle_sigint);
	if (ac == 1)
	{
		prompt_user(av, env);
	}
	return (0);
}
