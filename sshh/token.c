#include "sshh.h"

char **token(char *command)
{
	int i, k, words, wordlen;
	char **pcommand;
	char *tokopy= strtok(strdup(command), " ");

	for (words = 0; tokopy; words++)
	{
		tokopy = strtok(NULL, " ");
	}

	pcommand = malloc(sizeof(char *) * words);

	if (!pcommand)
	{
		printf("Malloc @pcommand failed\nExiting...\n");
		return (NULL);
	}

	tokopy = strtok(strdup(command), " \n\t");

	for (i = 0; tokopy; i++)
	{
		wordlen = strlen(tokopy);
		pcommand[i] = malloc((sizeof(char) * wordlen));
		if (!pcommand[i])
		{
			for (k = 0; k < i; k++)
				free(pcommand[k]);
			free(pcommand);
			printf("pcommand[%d] malloc error\nExiting...\n", i);
			return (NULL);
		}
		pcommand[i] = tokopy;
		printf("pcommand[%d]: %s\n", i, pcommand[i]);
		tokopy = strtok(NULL, " ");
	}

	printf("Number of words: %d\n", words);

	return (pcommand);
}
