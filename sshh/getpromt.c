#include "sshh.h"

char *getprompt(void)
{
	int byread;
        size_t size = 1;
        char *command = malloc(sizeof(char) * size);

        printf("$ ");
        byread = getline(&command, &size, stdin);

	if (!command)
	{
		printf("Malloc @command failed\nExiting...\n");
		return (0);
	}
	if (byread == -1)
	{
		free(command);
		printf("\nExiting...\n");
		return (NULL);
	}

	return(command);
}
