#include "shell.h"

int main(void)
{
	char **argv, *command_cpy = NULL;
	pid_t pid;

	while (1)
	{
		char *command = getprompt();
		if (!command)
			return(0);

		command_cpy = strdup(command);
		argv = tokenizer(command_cpy);

/**Execve doesen't works properly:
 * 	- doesn't executes all commands.
 * 	- valgrind is not happy.
 * 	- child processes already does not accumulates (but returns),
 * 	and I have no idea if that's what's supposed to do.
 */
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
			free(command), free(command_cpy), free(argv);
			return (0);
		}
		if (pid == 0)
			return (0);
		wait(NULL);

		free(command), free(command_cpy), free(argv);
	}
	return (1);
}
