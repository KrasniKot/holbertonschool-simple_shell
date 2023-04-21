#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int ac, char **av, char **env)
{
	char *environ= getenv(environ);
	printf("environ: %p\n", &environ);
	printf("env: %p\n", &env);
}
