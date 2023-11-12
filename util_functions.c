#include "shell.h"


/**
 * support_env_tasks - to enhance 'env' command functionality
 *
 * Return: void
 */
void support_env_tasks(void)
{
	const char *help =
	"env: env [option] [name=value] [command [args]]\n"
	"\tDisplay the shell's environment.\n";

	write(STDOUT_FILENO, help, _strlen(help));

}
/**
 * env_variable_support - Display assist for the 'setenv' function.
 * Return: void
 */
void env_variable_support(void)
{

	const char *help = "setenv: setenv (const char *name, const char *value,";
	const char *description = "Add a new definition to the environment\n";


	write(STDOUT_FILENO, help, _strlen(help));
	write(STDOUT_FILENO, description, _strlen(description));
}
/**
 * support_unsetenv_command - function to informats for the builtin unsetenv
 * Return: void
 */
void support_unsetenv_command(void)
{
	char *help =
	"unsetenv: unsetenv (const char *name)\n\t"
	"\tUse this command to eliminate an environment entry completely.\n";


	write(STDOUT_FILENO, help, _strlen(help));
}


/**
 * assist_general_command - Display help information for general commands
 * Return: nothing
 */
void assist_general_command(void)
{
	const char *help =
	"^-^ bash, version 1.0(1)-release\n"
	"The internal commands have been defined. Please use 'assist' to view the list.\n"
	"If you'd like additional information about the 'name' function, simply type 'assist name.'.\n"
	"alias: alias [name=['string']]\n"
	"cd: cd [-L|[-P [-e]] [-@]] [dir]\n"
	"exit: exit [n]\n"
	"env: env [option] [name=value] [command args]\n"
	"setenv: setenv [variable] [value]\n"
	"unsetenv: unsetenv [variable]\n";

	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * print_exit_help - Help provide information for exit command.
 *
 * Return: void
 */
void print_exit_help(void)
{
	const char *help =
	"exit: exit [n]\n Exit shell.\n"
	"Exits the shell with a status of N. If N is omitted,
	"the exit status is that of the last command executed.\n ";

	write(STDOUT_FILENO, help, _strlen(help));
}
