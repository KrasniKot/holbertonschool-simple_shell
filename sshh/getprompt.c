#include "shell.h"

char *getprompt(void)
{
	char *command = NULL;
	size_t size = 0;

	printf("$ ");
	if (getline(&command, &size, stdin) == -1)
	{
		free(command);
		printf("getline failed\nExiting...\n");
		return (0);
	}

	return (command);
}
