#include "shell.h"

/**
 * obtain_builtins - for builtin that pairs the command in the arg
 * @cmd: the command
 * Return: function pointer of builtin command
 */

int (*obtain_builtins(char *command))(data_container *)
{
	a_builtin built_in[] = {
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
		if (_strcmp(built_in[n].name, command) == 0)
			break;
	}

	return (built_in[n].f);
}
