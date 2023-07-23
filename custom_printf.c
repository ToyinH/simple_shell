#include "simple_shell.h"

/**
 * custom_printf - this function prints the supplied string
 * to the specified STDOUT
 * @str_in: the string to be printed
 * Return: void
 */

void custom_printf(const char *str_in)
{
	size_t str_len;

	str_len = strlen(str_in);
	write(STDOUT_FILENO, str_in, str_len);
}
