#include "sshh.h"

int freed(char **tcommand)
{
	int i;

//	for (i = 0; tcommand[i]; i++)
//		free(tcommand[i]);
	free(tcommand);

	return (i);
}
