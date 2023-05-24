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
#include <signal.h>

extern char **environ;

int _strcmp(char *string1, char *string2);
int _atoi(char *str);
size_t _strlen(const char *string);
int execpid(char *argv[], char *input, char *programme_name, size_t count);
char *_strdup(const char *str);
char *rm_nwline(char *str);
char **srt_input(char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_getenv(const char *name);
char *mkpath(char *path_tok, char *cmd);
char *path_maker(char *cmd);
void sigint_stop(int sig_num);
int builtin_checker(char **argv, int status, char *input);
void _free(char **mem);
void error_print(char *file, char *cmd, size_t count);
void print_int(size_t count);

#endif
