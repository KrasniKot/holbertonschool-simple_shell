#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

void main(void)
{
	char command[] = "ls -l /tmp";
	char *ps = strtok(command, " ");
	int i = 0;
	char *pps[4];
	pid_t pid_child;

	for (; ps; i++)
	{
		pps[i] = ps;
		ps = strtok(NULL, " ");
	}
	pps[i] = NULL;

	pid_child = fork();
	if (pid_child == 0)
	{
		if (execve("/usr/bin/ls", pps, NULL) == -1)
			perror("/usr/bin/ls");
	}
	else if (pid_child > 0)
	{
		wait(&pid_child);
	}
	else
		perror("fork failed");
}
