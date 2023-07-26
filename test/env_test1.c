#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("\naddress of env: %p\n", (void *)env);
	printf("\naddress of environ: %p\n", (void *)environ);
	return 0;
}
