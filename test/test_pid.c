#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	int status;
	pid_t parent, child, parent_f, child_f, return_fork;

	parent = getppid();
	child = getpid();
	printf("parent id: %u\n", parent);
	printf("child id: %u\n", child);

	return_fork = fork();
	if (return_fork == 0)
	{
		parent_f = getppid();
		child_f = getpid();
		printf("return fork id: %u\n", return_fork);
		printf("parent after forked id: %u\n", parent_f);
		printf("child after forked id: %u\n", child_f);
	}
	else if (return_fork > 0)
	{
		parent_f = getppid();
		child_f = getpid();
		printf("grandparent after forked failed id: %u\n", parent_f);
		printf("parent after forked failed id: %u\n", child_f);
	}
	else
	{
		perror("fork");
		return -1;

	}
	wait(&status);
	return 0;
}
