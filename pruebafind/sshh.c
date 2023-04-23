#include "shell.h"

int main(int ac, char **av)
{
	char **argv, *command_cpy = NULL;
	pid_t pid;

	while (1)
	{
		char *delim = " \n\t", *where;
		char *command = getprompt();
		int exe;

		if (!command)
			return (1);

		command_cpy = strdup(command);

		argv = tokenizer(command_cpy, delim);
//		exe = execute(command, command_cpy, argv);
		where = findcmd(argv[0]);
		printf("where: %s\n", where);

		free(command), free(command_cpy), free(argv);
	}
	return (0);
}
