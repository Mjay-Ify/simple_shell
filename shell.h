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


char *custom_strcat(char *custom_dest, const char *source);
char *custom_strcpy(char *custom_dest, char *source);
int custom_strcmp(char *str1, char *str2);
char *custom_strchr(char *str, char c);
int custom_strspn(char *str, char *receive);



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
int char_cmp(char s[], const char *delimiter);
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

int obtain_error(data_container *data, int val);
void assign_line(char **line_buff, size_t *a, char *buff, size_t b);
ssize_t obtain_line(char **line_buff, size_t *i, FILE *str);
char *read_input(int *n);
void obtain_signal(int sig_val);
int obtain_help(data_container *data);
int (*obtain_builtin(char *command))(data_container *);

int is_current_dir(char *path, int *i);
char *custom_which(char *command, char **environment_variable);
int custom_is_executable(data_container *data);
int verify_error_command(char *dir, data_container *data);
int command_execute(data_container *data);

int cmp_envn_alias(const char *n_env, const char *alias);
int print_envn(data_container *sh_data);
char *obtain_envn(const char *alias, char **envn);

int exe_command(data_container *sh_data);
int verify_cmd_err(char *dirs, data_container *sh_data);
int is_exec(data_container *sh_data);
char *loc_cmd(char *n_cmd, char **envn);
int _iscdire(char *way, int *n);

int del_envn(data_container *sh_data);
int cmp_envn(data_container *sh_data);
void put_envn(char *alias, char *val, data_container *sh_data);
char *cpy_data(char *alias, char *val);

int close_shell(data_container *data);

int find_b_cmd(data_container *data);
int obtain_line(data_container *data);

void custom_rev_string(char *str) 
int verify_syn_err(data_container *sh_data, char *insert);
void print_syn_err(data_container *sh_data, char *insert, int n, int bool);
int insert_char(char *insert, int *n);
int err_sep_op(char *insert, int n, char final);
int char_dup(char *insert, int n);

extern char **environ;

/**
 * struct data - struct containing all relevant data on runtime
 * @argv: argument vector
 * @insert: command line entered by the user
 * @args: tokens of the cosmmand line
 * @stat: last status of the shell
 * @count: counts line
 * @envn: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **argv;
	char *insert;
	char **args;
	int stat;
	int count;
	char **envn;
	char *pid;
} data_container;

/**
 * struct separator_list_s - single linked list
 * @sep: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct separator_list_s
{
	char sep;
	struct separator_list_s *next;
} separator_list;

/**
 * c_struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct c_line_list_s
{
	char *line;
	struct c_line_list_s *next;
} c_line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *value;
	int len_value;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, env, etc
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *alias;
	int (*f)(data_container *datash);
} builtin;

#endif
