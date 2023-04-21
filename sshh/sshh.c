#include "shell.h"

int main(int ac, char **av, char **env)
{
	char **argv, *command_cpy = NULL;
	pid_t pid;

	while (1)
	{
		char *command = getprompt();
		if (!command)
			return (0);

		command_cpy = strdup(command);
		argv = tokenizer(command_cpy);
		pid = fork();

		if (pid == -1)
		{
			printf("Could't create child process\nExiting...\n");
			return (0);
		}
		else if (!pid)
		{
			execve(argv[0], argv, env);
			perror("shell");
			free(command), free(command_cpy), free(argv);
			return (0);
		}

		wait(NULL);
		free(command), free(command_cpy), free(argv);
	}
	return (1);
}
