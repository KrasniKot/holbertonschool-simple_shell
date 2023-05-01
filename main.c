#include "shell.h"

/**
 * main - calls the concerned functions.
 * @ac: Number of arguments passed.
 * @av: arguments given.
 * Return: 0.
 */
int main(int ac, char **av)
{
	char *command_cpy = NULL, *shname = av[0];
	char *path, *delim = " \n\t", *command = NULL, **argv;
	int interactive = isatty(STDIN_FILENO);
	size_t size = 0;
	int status = 0, count = 0, b;
	(void)ac;

	while (1)
	{
		path = get_env("PATH");
		if (interactive == 1)
			printf("$ ");

		if (getline(&command, &size, stdin) == -1)
		{
			free(command);
			if (path && strlen(path))
				free(path);
			exit(status);
		}
		if (!command)
		{
			free(path);
			return (status);
		}

		command_cpy = strdup(command);
		argv = tokenizer(command_cpy, delim);
		b = built_call(command, command_cpy, argv, path, count);
		if (b == 1)
			status = eway(command, command_cpy, argv, path, shname);
		else
			status = b;
		free(command_cpy), free(argv);
		count++;
	}
	return (status);
}
