#include "shell.h"

/**
 * built_call - executes exit or env, depending on @av[0].
 * @cmd: command.
 * @cmdcpy: command copy.
 * @av: input.
 * @path: PATH.
 * @count: Number of iterations that main while loop executed.
 * Return: 0 if success, 1 if no bult-in command was executed.
 */
int built_call(char *cmd, char *cmdcpy, char **av, char *path, int count)
{
	int i;

	if (av[0])
	{
		if (!strcmp(av[0], "exit")) /*checks if command is "exit"*/
		{
			if (av[1] || count > 0)
			{
				free(cmd), free(cmdcpy), free(path);
				free(av);
				exit(2);
			}
			free(cmd), free(cmdcpy), free(av), free(path);
			exit(EXIT_SUCCESS);
		}
		if (!strcmp(av[0], "env")) /*checks if command is "env"*/
		{
			for (i = 0; environ[i]; i++)
				printf("%s\n", environ[i]);
			free(path);
			return (0);
		}
	}
	return (1);
}
