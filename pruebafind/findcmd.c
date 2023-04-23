#include "shell.h"

char *findcmd(char *cmd)
{
	struct stat st;

	char *path = get_env("PATH"), *delim = ":", where[40];
	char **tpath = tokenizer(path, delim);
	int i;

	for (i = 0; tpath[i]; i++)
	{
		strcpy(where, tpath[i]);
		strcat(where, cmd);
		printf("tpath[%d]: %s\n", i, where);
		if (!stat(where, &st))
		{
			printf("comamnd is in: %s\n", where);
			return (strcat(tpath[i], cmd));
		}
	}

	free(path), free(tpath);

	printf("command not found\n");
	return(NULL);
}
