#include "shell.h"

char **tokenizer(char *command)
{
	int i, argc;
	char **argv = NULL, *delim = " \n";
	char *command_cpy = strdup(command), *token = strtok(command_cpy, delim);
	
	for (argc = 0; token; argc++)
		token = strtok(NULL, delim);

	printf("argc: %d\n", argc);
	argv = malloc(sizeof(char *) * argc);

	free(command_cpy);
	command_cpy = strdup(command);
	token = strtok(command_cpy, delim);
	
	for (i = 0; token; i++)
	{
		argv[i] = token;
		printf("argv[%d]: %s\n", i, argv[i]);
		token = strtok(NULL, delim);
	}

	free(command_cpy);
	return (argv);
}
