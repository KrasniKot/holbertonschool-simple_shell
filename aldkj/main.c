#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
int main(void)
{
	struct stat st;

	char *route = "/bin/ls";

	if (!stat(route, &st))
	{
		printf("!stat\n");
		return (0);
	}

	printf("stat\n");
	return 0;
}
