#include "shell.h"


/**
 * support_env_tasks - to enhance 'env' command functionality
 *
 * Return: void
 */
void support_env_tasks(void)
{
	const char *support =
	"env: env [option] [name=value] [command [args]]\n\t";

	"Display the shell's environment.\n";
	write(STDOUT_FILENO, support, _strlen(support));

}
/**
 * env_variable_assist - Display help for the 'setenv' function.
 * Return: nothing
 */
void env_variable_support(void)
{

	const char *support = "setenv: setenv (const char *name, const char *value,";
	const char *description = "Add a new definition to the environment\n";


	write(STDOUT_FILENO, support, _strlen(support));
	write(STDOUT_FILENO, description, _strlen(description));
}
/**
 * support_unsetenv_command - function to informats for the builtin unsetenv
 * Return: void
 */
void support_unsetenv_command(void)
{
	char *support = "unsetenv: unsetenv (const char *name)\n\t"
			"\tUse this command to eliminate an environment entry completely.\n";


	write(STDOUT_FILENO, support, _strlen(support));
}


/**
 * support_general_command - Display help information for general commands
 * Return: nothing
 */
void support_general_command(void)
{
	char *support = "^-^ bash, version 1.0(1)-release\n";


	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_exit - Help information fot the builint exit
 * Return: nothing
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "status is that of the last command executed\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
