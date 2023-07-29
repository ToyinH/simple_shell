#include "simple_shell.h"
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
				custom_exit(argv);
			else if ((custom_strcmp("env", argv[0]) == 0)
				&& argv[1] != NULL)
			{
				_setenv(argv, env);
				free(argv);
				continue;
			}
			else if (custom_strcmp("setenv", argv[0]) == 0)
			{
				_setenv2(argv, env);
				free(argv);
				continue;
			}
			else if (custom_strcmp("unsetenv", argv[0]) == 0)
			{
				_unsetenv(argv);
				free(argv);
				continue;
			}
			else if (custom_strcmp("cd", argv[0]) == 0)
			{
				_cd(argv);
				free(argv);
				continue;
			}
			replace_variables(argv, env);
			new_str = file_check(argv[0]);

			if (new_str == NULL)
				premade_path(argv, av, env);

			/** else if (new_str == NULL && custom_strcmp("/bin/", argv[0]) != 0)
			{
				new_str = file_check2(argv);
				if (new_str != NULL)
				{
					argv[0] = new_str;
					fork_exec(argv, env, av);
				}
				else
				{
					_printf(av[0]);
					_printf(": No such file or directory\n");
				}
				if (argv[1] == NULL)
					free_argv(argv);
				else
					free_argv2(argv);

			} **/
			else if (new_str != NULL)
			{
				argv[0] = new_str;
				unpath(argv, av, env);
			}
		}
	}
}
