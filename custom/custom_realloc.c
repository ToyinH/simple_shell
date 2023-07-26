#include "simple_shell.h"
/**
 * _realloc - this function reallocs a block of memory
 * @pntr: this is the pointer to the previously memory block
 * @new_mem_size: size of the new memory block
 * Return: pointer to the old block name
 */
char *_realloc(char *pntr, size_t new_mem_size)
{
	size_t old_mem_size;
	char *new_ptr;

	if (!pntr)
		return (malloc(new_mem_size));
	if (new_mem_size == 0)
	{
		free(pntr);
		return (NULL);
	}
	new_ptr = malloc(new_mem_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_ptr)
	{
		old_mem_size = new_mem_size;
		if (old_mem_size > sizeof(pntr))
			old_mem_size = sizeof(pntr);
		_memcpy(new_ptr, pntr, old_mem_size);
		free(pntr);
	}
	return (new_ptr);
}
/**
 * _memcpy - function that copies memory
 * @dest: destination
 * @src: mem copied from
 * @n: size copied
 *
 * Return: return dest
 */

char *_memcpy(char *dest, char *src, size_t n)
{
	size_t i;
	char *dest_ptr = dest;
	char *src_ptr = src;

	for (i = 0; i < n; i++)
	{
		dest_ptr[i] = src_ptr[i];
	}
	return (dest);
}
