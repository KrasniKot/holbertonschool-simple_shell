#include <string.h>
#include <stdio.h>

void (main)(void)
{
	char buff[204] = "This is a string to be parsed";
	char *ps = strtok(buff, " ");

	for (;ps;)
	{
		printf("%s\n", ps);
		ps = strtok (NULL, " ");
	}
}
