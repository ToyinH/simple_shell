#include "simple_shell.h"

/**
 * main - function that creates my shell
 * @ac: argument count;
 * @av: argument vector
 * @envt: environment
 *
 * Return: return 0 if successful
 */
int main(int ac, char **av, char **envt)
{
	if (ac == 1)
	{
		prompt_user(av, envt);
	}
	return (0);
}
