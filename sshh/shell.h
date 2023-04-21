#ifndef nnn
#define nnn

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *getprompt(void);
char **tokenizer(char *command);

#endif
