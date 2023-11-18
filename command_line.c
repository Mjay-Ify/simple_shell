#include "shell.h"

/**
 * obtain_line -  Finds builtins and commands.
 *
 * @data: data relevant to the operations (args)
 * Return: 1 on success, indicating the successful
 * identification and processing
 *  * of built-ins and commands.
 */
int obtain_line(data_container *data)
{
	int (*builtin)(data_container *data);

	if (data->args[0] == NULL)
		return (1);

	builtin = obtain_builtins(data->args[0]);

	if (builtin != NULL)
		return (builtin(data));

	return (command_obtain(data));
}
