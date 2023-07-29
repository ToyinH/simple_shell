#include "simple_shell.h"
#include <limits.h>

#define MAX_INPUT_LENGTH 1024
/**
 *
 */

int _cd(char **argv)
{
	if (argv[1] == NULL)
	{
		/** No argument, use $HOME **/
		const char *home_path = getenv("HOME");

		if (home_path == NULL)
			_printf("cd: HOME environment variable not set\n");
		else
			change_directory(home_path);
	}
	else
	{
		change_directory(argv[1]);
	}
	return (0);
}

/**
 *
 */
void change_directory(const char *path)
{
	char current_path[PATH_MAX];
	char new_path[PATH_MAX];
	char *err;

	if (getcwd(current_path, sizeof(current_path)) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (custom_strcmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			_printf("cd: OLDPWD not set\n");
			return;
		}
	}
	if (chdir(path) != 0)
	{
		err = "./hsh: 1: cd: can't cd to /hbtn";
		write(STDERR_FILENO, err, _strlen(err));
		return;
	}
	/** Update PWD environment variable **/
	if (getcwd(new_path, sizeof(new_path)) == NULL)
	{
		perror("getcwd");
		return;
	}
	setenv("PWD", new_path, 1);
	setenv("OLDPWD", current_path, 1);
}
