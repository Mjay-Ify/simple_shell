#include "main.h"

/**
 * find_b_cmd - Searches for and executes built-in commands.
 * @data: Pointer to the data_container structure containing shell data.
 * Return: 1 on success, 0 if no built-in command is found.
 */
int find_b_cmd(data_container *data)
{
	int (*built_in)(data_container *data);

	if (data->args[0] == NULL)
		return (1);

	built_in = obtain_builtin(data->args[0]);

	if (built_in != NULL)
		return (built_in(data));

	return (command_execute(data));
}
