#include "sshh.h"

int main(void)
{
	while (1)
	{
		char *command = getprompt();
		char **tcommand;

		if (!command)
			return (0);
		tcommand = token(command);

		free(command);
		freed(tcommand);
	}
	return (0);
}
