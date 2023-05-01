#include "shell.h"

/**
 * execute - creates a child process and executes.
 * @cmd: command to be executed.
 * @cmdcpy: @command duplicated.
 * @av: each word of command.
 * @path: PATH.
 * Return: if couldn't create child proccess -1, exit status if success.
 */
int execute(char *cmd, char *cmdcpy, char **av, char *path)
{
	int status, exit_status;
	pid_t pid = fork(); /*creating a child process*/

	if (pid == -1)
	{
		perror("Error");
		free(path);
		return (-1);
	}
	if (!pid)
	{
		/*executing the command already processed or returning error*/
		if (execve(av[0], av, environ) == -1)
		{
			perror("Shell");
			free(cmd), free(cmdcpy), free(av);
			free(path);
			exit(errno);
		}
	}
	waitpid(pid, &status, 0);

	/*transforming the executable return value into the corresponding one*/
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
 * @shn: Shell name.
 * Return: calls the concerned function or 127 if it fails.
 */
int eway(char *cmd, char *cmdcpy, char **av, char *path, char *shn)
{
	struct stat st;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == 47 || cmd[i] == 91) /*checking for '/' or '['*/
		{
			/*executing the executable if it exists*/
			if (!stat(av[0], &st))
				return (execute(cmd, cmdcpy, av, path));
			/*getting the error message*/
			execve(av[0], av, environ);
			perror("Shell");
			free(path);
			return (127);
		}
	}
	return (exec_no_path(av, path, cmdcpy, cmd, shn));
}

/**
 * exec_no_path - adds the route of the command.
 * @cmd: command to be executed.
 * @cmdcpy: @command duplicated.
 * @av: each word of command.
 * @path: PATH.
 * @shn: Shell name.
 * Return: calls to execute if the command exists, 127 if not.
 */
int exec_no_path(char **av, char *path, char *cmdcpy, char *cmd, char *shn)
{
	char *where = NULL;

	if (av[0]) /*looking for the executable location*/
		where = findcmd(av[0], path);

	if (av[0] && where)
	{
		/*executing the executable*/
		av[0] = where;
		return (execute(cmd, cmdcpy, av, path));
	}

	if (!av[0])
	{
		if (path)
			free(path);
		return (0);
	}

	/*no location found*/
	dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", shn, av[0]);
	if (path && strlen(path))
		free(path);
	return (127);
}
