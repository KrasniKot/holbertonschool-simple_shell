#ifndef nnn
#define nnn

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

char **tokenizer(char *command, char *delim);
char *get_env(char *env_name);
int eway(char *cmd, char *cmdcpy, char **av, char *path, char *shn);
int execute(char *cmd, char *cmdcpy, char **av, char *path);
int exec_no_path(char **av, char *path, char *cmdcpy, char *cmd, char *shn);
char *findcmd(char *cmd, char *path);
int built_call(char *cmd, char *cmdcpy, char **av, char *path, int count);

#endif
