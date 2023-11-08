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

#define BUFFERSIZE 1024
#define TOKEN_BUFFERSIZE 128
#define TOKEN_SEP " \t\r\n\a"

char *strcat_custom(data_container *, char *, char *, char *);
char *fetch_error_custom(data_container *data);
char *missing_file_error(data_container *data);
char *shell_terminate_error(data_container *data);

void support_unsetenv_command(void)
void env_variable_support(void)
void support_env_tasks(void)
void assist_general_command(void)
void print_exit_help(void)

void env_assist_alias(void)
void env_assist(void) 
void env_assist_cd(void)  

char *del_comment(char *insert);
void looping_sh(data_container *sh_data);

char *system_environment_error(data_container *data)
char *route_126_error_alert(data_container *data)

char **crack_line(char *insert);
int crack_cmd(data_container *sh_data, char *insert);
void next_line(sep_list **separator_list, c_line_list **line_list, data_container *sh_data);
void add_separators(separator_list **sep_head, c_line_list **line_head, char *insert);
char *replace_char(char *insert, int bool);

#endif
