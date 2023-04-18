#include <stdio.h>
#include <string.h>

void main(void)
{
	char buff[] = "This is a string to be parsed";
	char *ps = strtok(buff, " ");

	while (ps)
	{
		printf("%s\n", ps);
		ps = strtok (NULL, " ");
	}
}
