#include "simple_shell.h"
/**
 *
 */

int _cd2(char **argv)
{
	char *path = argv[1];
	char current_path[PATH_MAX];
	char new_path[PATH_MAX];
	char *err = "./hsh: 1: cd: can't cd to ";
	char *home_path;

	if (path == NULL || custom_strcmp(path, "~") == 0)
	{
		/** No argument or ~, use $HOME **/
		home_path = getenv("HOME");
		if (home_path == NULL)
		{
			_printf("cd: HOME environment variable not set\n");
			return (0);
		}
	}
	path = home_path;
	if (custom_strcmp(path, "-") == 0)
	{
		/** cd - **/
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			write(STDERR_FILENO, err, _strlen(err));
			return (0);
		}
	}
	if (chdir(path) != 0)
	{
		write(STDERR_FILENO, err, _strlen(err));
		return (0);
	}
	/** Update PWD environment variable **/
	if (getcwd(new_path, sizeof(new_path)) == NULL)
	{
		perror("getcwd");
		return (0);
	}
	setenv("PWD", new_path, 1);
	setenv("OLDPWD", current_path, 1);
	return (0);
}
