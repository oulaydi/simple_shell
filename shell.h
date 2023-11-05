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



char *read_line(void);
char **splitting_line(char *line);
void execution(char **command);
void free_lmlawi(char **array);

#endif
