#include "shell.h"

/**
 * obtain_line - function to finds builtins and commands
 *
 * @data: data relevant (args)
 * Return: 1 on success.
 */
int obtain_line(data_container *data)
{
	int (*builtin)(data_container *datash);

	if (data->args[0] == NULL)
		return (1);

	builtin = obtain_builtin(data->args[0]);

	if (builtin != NULL)
		return (builtin(data));

	return (exe_command(data));
}
