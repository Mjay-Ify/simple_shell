#include "shell.h"

/**
 * obtain_help - function that obtains the help msg according to builtin
 * @sh_data: data of  the structure (args and input)
 * Return: 0
*/

int obtain_help(data_container *sh_data)
{

	if (sh_data->args[1] == 0)
		aux_help_general();
	else if (_strcmp(sh_data->args[1], "setenv") == 0)
		aux_help_setenv();
	else if (_strcmp(sh_data->args[1], "env") == 0)
		aux_help_env();
	else if (_strcmp(sh_data->args[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (_strcmp(sh_data->args[1], "help") == 0)
		aux_help();
	else if (_strcmp(sh_data->args[1], "exit") == 0)
		aux_help_exit();
	else if (_strcmp(sh_data->args[1], "cd") == 0)
		aux_help_cd();
	else if (_strcmp(sh_data->args[1], "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, sh_data->args[0],
		      _strlen(sh_data->args[0]));

	sh_data->stat = 0;
	return (1);
}
