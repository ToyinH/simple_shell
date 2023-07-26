#include "simple_shell.h"
/**
 * handle_sigint - function to handle ctrl+C
 * @signum: signint
 */
void handle_sigint (int signum __attribute__((unused)))
{
	exit(EXIT_SUCCESS);
}
