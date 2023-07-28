#include "simple_shell.h"
#define MAX 10
/**
 * prompt_user - function that handles user prompts
 * @av: argument vector
 * @env: environment
 * Return: void
 */

void prompt_user(char **av, char **env)
{
	char *str = NULL, *new_str, **argv;
	int i;

	while (true)
	{
		if (isatty(STDIN_FILENO))
		{
			_printf("#cisfun$ ");
			fflush(stdout);
		}
		str = handl_getline();
		if (space_character(str))
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
				if (argv[1] != NULL)
				{
					free_argv(argv);
					exit((atoi)argv[1]);
				}
				/** free(str); **/
				free(argv);
				exit(EXIT_SUCCESS);
			}
			new_str = file_check(argv[0]);
			if (new_str == NULL)
				premade_path(argv, av, env);
			else if (new_str != NULL)
			{
				argv[0] = new_str;
				unpath(argv, av, env);
			}
		}
	}
}
