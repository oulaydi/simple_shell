#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syscall.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/syscall.h>

extern char **environ;


char *read_line(void);
char **splitting_line(char *line);
void execution(char **command);
void free_lmlawi(char **array);
char *exec_path(char *command);
char *find_path(char *path);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *src);
void cmd_error_handle(char *cmd);
int exit_status(char **arr);
int _isdigit(int c);
void print_number(int n);
void exit_neg_err(int num);
int _putchar(char c);
void env_print(void);
int _atoi(const char *str);

#endif
