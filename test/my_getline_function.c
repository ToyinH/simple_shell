#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"
/**
 *
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buf_size = *n;
	char *new_lineptr;
	int c;
	int pos = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("invalid entry");
		return(-1);
	}
	if (*lineptr == NULL || buf_size == 0)
	{
		buf_size = 128;
		*lineptr = malloc(buf_size);
		if (*lineptr == NULL)
		{
			perror("memory allocation failed");
			return (-1);
		}
	}
	while((c = fgetc(stream)) != EOF)
	{
		if (pos >= buf_size - 1)
		{
			buf_size *= 2;
			new_lineptr = realloc(*lineptr, buf_size);
			if (new_lineptr == NULL)
			{
				perror("memory reallocation failed");
				return (-1);
			}
			*lineptr = new_lineptr;
		}
		(*lineptr)[pos] = c;
		pos++;
		if (c == '\n')
			break;
	}
	(*lineptr)[pos] = '\0';
	*n = buf_size;
	if (pos == 0 && c == EOF)
	{
		free(*lineptr);
		*lineptr == NULL;
		perror("No character read");
		return (-1);
	}
	return ((ssize_t)pos);

}
