#include "simple_shell.h"
/**
 * file_check - function to check the command in the /bin/ file
 * @string: string to search
 *
 * Return: return the new concatenated string or NULL if unsuccessful
 */
char *file_check(char *string)
{
	char *temp, *new_string;
	struct dirent *reader;

	DIR *dir = opendir("/bin/");

	if (dir == NULL)
		return (NULL);
	reader = readdir(dir);
	if (reader == NULL)
		return (NULL);
	while (reader != NULL)
	{
		temp = reader->d_name;
		if (custom_strcmp(string, temp) == 0)
		{
			new_string = malloc(sizeof(char) * 32);
			if (new_string == NULL)
				return (NULL);
			strcpy(new_string, "/bin/");
			new_string = strcat(new_string, string);
			closedir(dir);
			return (new_string);
		}
		reader = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
