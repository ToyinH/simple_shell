#include "simple_shell.h"
#define MAX 10
/**
 * prompt_user - function that handles user prompts
 * @av: argument vector
 * @envt: environment
 */

void prompt_user(char **av, char **envt)
{
	char *str = NULL;
	int i = 0, status;
	char **argv;
	pid_t child_pid;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");
		str = handl_getline();
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = '\0';
			i++;
		}
		argv = handl_strtok(str, " ");
		child_pid = fork();
		if (child_pid == -1)
			free(str), exit(EXIT_FAILURE);
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, envt) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}
