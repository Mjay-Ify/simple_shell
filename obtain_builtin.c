#include "shell.h"

/**
 * obtain_builtin - Find & return function pointer for a built-in cmd
 * @command: the command string
 * Return: Function pointer to the corresponding built-in cmdd
 */

int (*obtain_builtin(char *command))(data_container *)
{
	builtin built_in[] = {
		{ "env", _env },
		{ "exit", exit_sh },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_sh },
		{ "help", obtain_help },
		{ NULL, NULL }
	};
	int n;

	for (n = 0; built_in[n].name; n++)
	{
		if (custom_strcmp(built_in[n].alias, command) == 0)
			break;
	}

	return (built_in[n].f);
}
