#include "shell.h"

char *getprompt(void)
{
	char *command = NULL;
	size_t size = 0;
	int interactive = isatty(STDIN_FILENO);

	if (interactive == 1)
		printf("$ ");
	if (getline(&command, &size, stdin) == -1)
	{
		free(command);
		exit(EXIT_FAILURE);
	}
	return (command);
}
