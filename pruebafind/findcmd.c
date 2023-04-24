#include "shell.h"

char *findcmd(char *cmd)
{
	struct stat st;

	int i, k = strlen(cmd);
	char *path = get_env("PATH"), **tpath = tokenizer(path, ":");
	char *in;
	char u_cmd[k + 2];
	char where[40];

	u_cmd[0] = 47;
	for (i = 1; i <= k; i++)
		u_cmd[i] = cmd[i - 1];
	u_cmd[k + 1] = '\0';

	for (i = 0; tpath[i]; i++)
	{
		strcpy(where, tpath[i]);
		strcat(where, u_cmd);
		printf("tpath[%d]: %s\n", i, where);
		if (!stat(where, &st))
		{
			printf("comamnd is in: %s\n", where);
			in = strcat(tpath[i], u_cmd);
			free(path), free(tpath);
			return (in);
		}
	}

	free(path), free(tpath);
	printf("command not found\n");
	return(NULL);
}
