#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"
char *strcat_custom(data_container *, char *, char *, char *);
char *fetch_error_custom(data_container *data);
char *missing_file_error(data_container *data);
char *shell_terminate_error(data_container *data);
#endif
