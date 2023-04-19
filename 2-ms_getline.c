#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int byread;
	size_t size;
	char *string = malloc(sizeof(char) * size);

	printf("> ");
	byread = getline(&string, &size, stdin);
	printf("%s\n", string);
}
