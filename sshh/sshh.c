#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int argc, i;
	char *delim = " \n", *command = NULL, *command_cpy = NULL, *token;
	char **argv;
	size_t size = 0;
	
	
	printf("$ ");
	if (getline(&command, &size, stdin) == -1)
			return (0);

	token = strtok(command, delim);

	for (argc = 0; token; argc++)
		token = strtok(NULL, delim);

	argv = malloc(sizeof(char *) * argc);

	token = strtok(command, delim);
	for (i = 0; i < argc; i++)
	{
		argv[i] = token;
	}
	argv[i] = NULL;

//	execve(argv[0], argv);

	free(command), free (argv), free(command_cpy);
	return(0);
}
