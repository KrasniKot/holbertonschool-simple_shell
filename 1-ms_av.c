#include <stdio.h>

void main(int argc, char **argv)
{
	(void)argc;
	int i = 0;

	for (; argv[i]; i++)
	{
		printf("%s\n", argv[i]);
	}

}
