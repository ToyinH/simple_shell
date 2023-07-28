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

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = buffer1;
	}
	while (true)
	{
		read_count = read(STDIN_FILENO, &c, 1);
		if (read_count == 0)
			exit(EXIT_SUCCESS);
		if (read_count == -1)
			exit(EXIT_SUCCESS);
		if (c == '\n')
		{
			(*lineptr)[pos] = '\0';
			return (pos);
		}
		(*lineptr)[pos++] = c;
	}
	(*lineptr)[pos] = '\0';
	return (pos);
}
