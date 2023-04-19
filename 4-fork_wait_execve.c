#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i;
	char command[] = "ls -l /tmp";
	char *pc = strtok(command, " ");
	char *pca[4];

	for (i = 0; pc; i++)
	{
		pca[i] = pc;
		pc = strtok(NULL, " ");
	}
	pca[i] = NULL;

	execve("/bin/ls", pca, NULL);

	perror("execve failed");
}
