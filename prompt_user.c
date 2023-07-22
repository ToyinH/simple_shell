#include "simple_shell.h"
#define MAX 10
/**
 * prompt_user - function that handles user prompts
 * @av: argument vector
 * @env: environment
 */

void prompt_user(char **av, char **env)
{
	char *str = NULL;
	char *new_str;
	int i;
	char **argv;

	while (true)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("cisfun$ ");
			fflush(stdout);
		}
		str = handl_getline();
		if (str[0] != '\n')
		{
			i = 0;
			while (str[i])
			{
				if (str[i] == '\n')
					str[i] = '\0';
				i++;
			}
			argv = handl_strtok(str, " ");
			if (custom_strcmp("exit", argv[0]) == 0)
			{
				free(str);
				free(argv);
				exit(EXIT_FAILURE);
			}
			new_str = file_check(argv[0]);
			if (new_str == NULL)
			{
				premade_path(argv, av, env, str);
			}
			else if (new_str != NULL)
			{
				argv[0] = new_str;
				unpath(argv, av, env, str);
			}
		}
	}
}
