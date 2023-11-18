#include "shell.h"


/**
 * execute_line -  Finds builtins and commands.
 * @data: data relevant to the operations (args)
 * Return: 1 on success, indicating the successful
 * identification and processing of built-ins and commands.
 */
int execute_line(data_container *data)
{
	int (*builtin)(data_container *data);
	int (*built_in)(data_container *datash);

	if (data->args[0] == NULL)
		return (1);

	built_in = obtain_builtin(data->args[0]);

	if (built_in != NULL)
		return (built_in(data));

	return (command_execute(data));
}
