#include "simple_shell.h"
/**
 * handle_sigint - function to handle ctrl+C
 * @signum: signint
 */
void handle_sigint (int signum __attribute__((unused)))
{
	/** _printf("\n");
	write(STDOUT_FILENO, "$ ", 2); **/
	exit(EXIT_SUCCESS);
}
