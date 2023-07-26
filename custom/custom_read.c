#include "simple_shell.h"
#define BUFFER_SIZE 1024

/**
 * custom_read - custom read function
 * @fd: file descriptor
 * @buf: buffer
 * @count: count of character to be read
 *
 * Return: return character read
 * Description: Use a buffer to read many chars at once and the least
 * possible the read system call
 * You need to use static variables
 */

ssize_t custom_read(int fd, void *buf, size_t count)
{
	static char buffer[BUFFER_SIZE];
	static int position;
	static int buffer_size;
	size_t remaining;
	size_t to_read, i;

	if (position >= buffer_size)
	{
		buffer_size = read(fd, buffer, BUFFER_SIZE);
		if (buffer_size <= 0)
		{
			return (buffer_size);
		}
		position = 0;
	}
	remaining = buffer_size - position;
	to_read = count < remaining ? count : remaining;
	for (i = 0; i < to_read; i++)
	{
		((char *)buf)[i] = buffer[position++];
	}
	return (to_read);

}
