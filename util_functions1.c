#include "shell.h"


/**
 * env_assist - Display brief summaries of builtin commands.
 * Return: void.
 */

void env_assist(void)
{
	char *assist =
	"assist: assist [-dms] [pattern ...]\n"
	"\tDisplay information about builtin commands.\n"

	"Displays brief summaries of builtin commands.\n";

	write(STDOUT_FILENO, assist, _strlen(assist));
}

/**
 * env_assist_alias - Access help documentation
 * for the built-in 'alias' command.
 *
 * Return: void
 */

void env_assist_alias(void)
{
	char *assist =
	"alias: alias [-p] [name[=value]...]\n"
	"\tDefine or display aliases.\n ";

	write(STDOUT_FILENO, assist, _strlen(assist));
}

/**
 * env_assist_cd - Assist information for the built-in cd command.
 *
 * Return: no return
 */

void env_assist_cd(void)
{
	char *assist =
	"cd: cd [-L|[-P [-e]] [-@]] [dir]\n"
	 "\tChange the shell working directory.\n ";

	write(STDOUT_FILENO, assist, _strlen(assist));
}
