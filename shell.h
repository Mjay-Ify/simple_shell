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

void support_unsetenv_command(void);
void env_variable_support(void;)
void support_env_tasks(void);
void assist_general_command(void);
void print_exit_help(void);

void env_assist_alias(void);
void env_assist(void);
void env_assist_cd(void);

line_list *append_line_to_end(line_list **list, char *line);
void deallocate_sep_list(sep_list **list);
sep_list *append_sep_to_end(sep_list **list, char seperator);
void free_line_list(line_list **list);

char *del_comment(char *insert);
void looping_sh(data_container *data);

int is_number(const char *str);
char *custom_strtok(char input_str[], const char *delimiter);
int hasDelimiter(char s[], const char *delimiter);
int custom_strlen(const char *str);
char *custom_strdup(const char *str);



int count_digit(int n);
char *intToStr(int n);
int custom_atoi(const char *str);


void custom_memcpy(void *destination, const void *source, unsigned int size);
char **resizedp(char **src, unsigned int orig_size, unsigned int new_size);
void *custom_realloc(void *src, unsigned int orig_size, unsigned int new_size);


void deallocate_rvar_list(r_var **list);
r_var *append_to_rva(r_var **list, int lvar, char *value, int lval);

char *system_environment_error(data_container *data);
char *route_126_error_alert(data_container *data);

char *replace_var(char *insert, data_container *data);
char *rep_insert(r_var **list, char *insert, char *new_insert, int n_len);
int verify_var(r_var **heads, char *insert, char *stat, data_container *data);
void verify_envn(r_var **heads, char *insert, data_container *data);

char **crack_line(char *insert);
int crack_cmd(data_container *data, char *insert);
void next_line(sep_list **sep_list, c_line_list **l_list, data_container *data);
void add_sep(sep_list **sep_head, c_line_list **line_head, char *insert);
char *replace_char(char *insert, int bool);

int obtain_errors(data_container *sh_data, int val);

void assign_line(char **line_buff, size_t *a, char *buff, size_t b)
ssize_t obtain_line(char **line_buff, size_t *i, FILE *str);

char *read_input(int *n);

#endif
