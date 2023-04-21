#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strcmp(const char *string1, const char *string2);
int _strlen(const char *string);
int execpid(char *command, char *argv[], char *env[]);

#endif
