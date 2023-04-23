#include "shell.h"

int execute(char *command, char *command_cpy, char **av)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return(-1);
	}
	if (!pid)
	{
		execve(av[0], av, environ);
		perror("Shell");
		free(command), free(command_cpy), free(av);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	return (0);
}
