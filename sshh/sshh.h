#ifndef nnn
#define nnn

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *getprompt(void);
char **token(char *command);
int freed(char **tcommand);
#endif
