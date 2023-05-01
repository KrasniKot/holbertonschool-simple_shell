#include "shell.h"

/**
 * tokenizer - splits an array into tokens.
 * @command: array to be splited.
 * @delim: array of delimiters.
 * Return: splited array.
 */
char **tokenizer(char *command, char *delim)
{
	int i, argc;
	char **argv = NULL;
	char *command_cpy = strdup(command), *token = strtok(command_cpy, delim);

	/*counting the number of words in the string*/
	for (argc = 1; token; argc++)
		token = strtok(NULL, delim);

	/*creating enough space to contain the splitted string*/
	argv = malloc(sizeof(char *) * argc);
	if (argv == NULL)
		return (NULL);

	free(command_cpy);
	token = strtok(command, delim);

	/*storing the splitted string into the double array*/
	for (i = 0; token; i++)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
