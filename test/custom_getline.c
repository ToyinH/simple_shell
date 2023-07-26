#include "simple_shell.h"
#define BUFFER_SIZE 1024

/**
 * custom_getline - my getline function
 * @lineptr: buffer
 * @n: size of character
 *
 * Return: return character read
 * Description: Use a buffer to read many chars at once and the least
 * possible the read system call
 * You need to use static variables
 */

ssize_t custom_getline(char **lineptr, size_t *n)
{
	ssize_t read_count;
	char c;
	size_t pos = 0;
	char *new_lineptr;

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (true)
	{
		read_count = custom_read(STDIN_FILENO, &c, 1);
		if (read_count <= 0)
			return (-1);
		if (c == '\n')
		{
			(*lineptr)[pos] = '\0';
			return (pos);
		}
		(*lineptr)[pos++] = c;
		if (pos >= *n - 1)
		{
			*n = *n * 2;
			new_lineptr = _realloc(*lineptr, *n);
			if (new_lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_lineptr;
		}
	}
	(*lineptr)[pos] = '\0';
	return (pos);
}
