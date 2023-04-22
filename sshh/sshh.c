#include "shell.h"

int main(int ac, char **av)
{
	char **argv, *command_cpy = NULL;
	pid_t pid;

	while (1)
	{
		char *delim = " \n\t";
		char *command = getprompt();

		if (!command)
			return (1);

		command_cpy = strdup(command);
		argv = tokenizer(command_cpy, delim);
		pid = fork();
		if (pid == -1)
		{
			printf("Could't create child process\nExiting...\n");
			return (1);
		}
		else if (!pid)
		{
			execve(argv[0], argv, environ);
			perror("shell");
			free(command), free(command_cpy), free(argv);
			return (1);
		}

		wait(NULL);
		free(command), free(command_cpy), free(argv);
	}
	return (0);
}
