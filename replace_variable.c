#include "simple_shell.h"
/**
 *
 *
 */
void replace_variables(char **argv, char **env)
{
	int i, j;

	for (i = 0; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '$')
		{
			/* Skip the '$' character */
			char *var = &argv[i][1];
			if (custom_strcmp("?", var) == 0)
			{
				/*Assuming the exit status will be a 3-digit number */
				char status_code[4];
				sprintf(status_code, "%d", exit_status);
				argv[i] = strdup(status_code);
			}
			else if (custom_strcmp("$", var) == 0)
			{
				/*Assuming process ID can be represented in 9 digits*/
				char pid[10];
				sprintf(pid, "%d", getpid());
				argv[i] = strdup(pid);
			}
			else
				/*Handle environment variable replacement*/
				for (j = 0; env[j] != NULL; j++)
				{
					if (strncmp(env[j], var, strlen(var)) == 0
							&& env[j][strlen(var)] == '=')
					{
						char *value = &env[j][strlen(var) + 1];
						argv[i] = strdup(value);
						free(argv[i]);
						break;
					}
				
				}
		}
	}
}
