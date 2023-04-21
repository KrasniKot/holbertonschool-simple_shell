#include <unistd.h>
#include <stdio.h>

void main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = getpid();
	pid = getppid();
	printf("pid: %u\n", pid);
	printf("ppid: %u\n", ppid);

}

