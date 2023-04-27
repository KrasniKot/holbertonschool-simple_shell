#include "shell.h"

/**
 * main - calls the concerned functions.
 * @ac: Number of arguments passed.
 * @av: arguments given.
 * Return: 0.
 */
int main(int ac, char **av)
{
	char *command_cpy = NULL;
	char *path, *delim = " \n\t", *command = NULL, **argv;
	int interactive = isatty(STDIN_FILENO);
	size_t size = 0;
	int status = 1;
	(void)av, (void)ac;

	while (1)
	{
		path = get_env("PATH");
		if (interactive == 1)
			printf("$ ");

		if (getline(&command, &size, stdin) == -1)
		{
			free(command), free(path);
			exit(status);
		}
		if (!command)
		{
			free(path);
			return (status);
		}

		command_cpy = strdup(command);
		argv = tokenizer(command_cpy, delim);
		status = eway(command, command_cpy, argv, path);
		free(command_cpy), free(argv);
	}
	return (status);
}
