#include "shell.h"

int main(int ac, char **av)
{
	char *command_cpy = NULL;
	char *path, *delim = " \n\t", *command, **argv;
	int exe;
	pid_t pid;

	while (1)
	{
		command = getprompt();
		if (!command)
		{
			free(path);
			return (1);
		}

		path = get_env("PATH");
		command_cpy = strdup(command);
		argv = tokenizer(command_cpy, delim);
		exe = eway(command, command_cpy, argv, path);

		free(command), free(command_cpy), free(argv), free(path);
	}
	return (0);
}
