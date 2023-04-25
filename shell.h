#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp(const char *string1, const char *string2);
int _strlen(const char *string);
int execpid(char *command, char *argv[], char *env[]);
char *_strdup(const char *str);
char *rm_nwline(char *str);
char **srt_input(char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_getenv(const char*name);

#endif
