#include "shell.h"

int main(void)
{
	int argc, i;
	char *delim = " \n", *command_cpy = NULL, *token;
	char **argv = NULL;
	size_t size = 1;
	pid_t pid;

	while (1)
	{
		char *command = getprompt();
		if (!command)
			return(0);

		command_cpy = strdup(command);
		token = strtok(command, delim);
	
		for (argc = 0; token; argc++)
			token = strtok(NULL, delim);
	
		argv = malloc(sizeof(char *) * argc);
	
		token = strtok(command_cpy, delim);
		for (i = 0; i < argc; i++)
		{
			argv[i] = token;
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		pid = fork();

		if (pid == -1)
		{
			printf("Could't create child process\nExiting...\n");
			return (0);
		}
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
			perror("the re shell");
		}
		wait(NULL);
		free(command), free(command_cpy), free(argv);
	}
	return (1);
}
