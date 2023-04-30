#include "shell.h"

/**
 * main - calls the concerned functions.
 * @ac: Number of arguments passed.
 * @av: arguments given.
 * Return: 0.
 */
int main(int ac, char **av)
{
	char *shname = av[0];
	char *path, *delim = " \n\t", *command = NULL, **argv;
	int interactive = isatty(STDIN_FILENO);
	size_t size = 0;
	int status = 0, count = 0, b;
	(void)ac;

	while (1)
	{
		path = get_env("PATH"); /*getting the PATH*/

		if (interactive == 1)
			printf("$ ");
		if (getline(&command, &size, stdin) == -1) /*storing the input in command*/
		{
			free(command);
			if (path && strlen(path))
				free(path);
			exit(status);
		}
		argv = tokenizer(command, delim); /*splitting the command into tokens*/

		/*checking for built-in commands in order to execute them*/
		b = built_call(command, argv, path, count);
		if (b == 1)
			status = eway(command, argv, path, shname); /*executing the command*/
		else
			status = b;
		free(argv);
		count++;
	}
	return (status);
}
