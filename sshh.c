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
	int exe, interactive = isatty(STDIN_FILENO);
	size_t size = 0;

	while (1)
	{
		if (interactive == 1)
			printf("$ ");

		if (getline(&command, &size, stdin) == -1)
		{
			free(command);
			printf("\n");
			exit(EXIT_FAILURE);
		}
		if (!command)
		{
			free(path);
			return (1);
		}
		if (command[0] == '\n')
			continue;

		path = get_env("PATH");
		command_cpy = strdup(command);
		argv = tokenizer(command_cpy, delim);
		exe = eway(command, command_cpy, argv, path);
		free(command_cpy), free(argv), free(path);
	}
	return (0);
}
