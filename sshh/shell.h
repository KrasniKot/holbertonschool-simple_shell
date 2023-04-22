#ifndef nnn
#define nnn

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *getprompt(void);
char **tokenizer(char *command, char *delim);
char *get_env(char *env_name);

#endif
