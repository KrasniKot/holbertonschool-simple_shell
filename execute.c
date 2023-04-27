#include "shell.h"

/**
 * execute - creates a child process and executes.
 * @command: command to be executed.
 * @command_cpy: @command duplicated.
 * @av: each word of command.
 * @path: PATH.
 * Return: if couldn't create child proccess -1, exit status if success.
 */
int execute(char *command, char *command_cpy, char **av, char *path)
{
	int status, exit_status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		free(path);
		return (-1);
	}
	if (!pid)
	{
		if (execve(av[0], av, environ) == -1)
		{
			perror("Shell");
			free(command), free(command_cpy), free(av);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, &status, 0);

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
	}
	free(path);
	return (exit_status);
}

/**
 * eway - checks for '/' in @av[0], and exits if @av[0] is "exit".
 * @cmd: command to be executed.
 * @cmdcpy: @command duplicated.
 * @av: each word of command.
 * @path: PATH.
 * Return: calls the concerned function or 127 if it fails.
 */
int eway(char *cmd, char *cmdcpy, char **av, char *path)
{
	struct stat st;

	int i;

	if (av[0])
	{
		if (!strcmp(av[0], "exit"))
		{
			if (av[1])
			{
				free(cmd), free(cmdcpy), free(path);
				free(av);
				exit(2);
			}
			free(cmd), free(cmdcpy), free(av), free(path);
			exit(EXIT_SUCCESS);
		}
	}
	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == 47 || cmd[i] == 91)
		{
			if (!stat(av[0], &st))
			{
				return (execute(cmd, cmdcpy, av, path));
			}
			execve(av[0], av, environ);
			perror("Shell");
			free(path);
			return (127);
		}
	}

	return (exec_no_path(av, path, cmdcpy, cmd));

}

/**
 * exec_no_path - adds the route of the command.
 * @cmd: command to be executed.
 * @cmdcpy: @command duplicated.
 * @av: each word of command.
 * @path: PATH.
 * Return: calls to execute if the command exists, 127 if not.
 */
int exec_no_path(char **av, char *path, char *cmdcpy, char *cmd)
{
	char *where = NULL;

	if (av[0])
		where = findcmd(av[0], path);

	if (av[0] && where)
	{
		av[0] = where;
		return (execute(cmd, cmdcpy, av, path));
	}

	dprintf(STDERR_FILENO, "Shell: 1: %s: not found\n", av[0]);
	free(path);
	return (127);
}
