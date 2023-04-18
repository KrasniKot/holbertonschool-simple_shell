#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int chars_read;
	size_t size;
	char *string = malloc(sizeof(char) * size);

	printf("$ ");
	chars_read = getline(&string, &size, stdin);
	printf("%s\n", string);
}
