#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void main(void)
{
	pid_t ppid;
	pid_t pid;

	ppid = getppid();
	pid = getpid();

	printf("ID parent process %u\n", ppid);
	printf("ID child process %u\n", pid);
}
