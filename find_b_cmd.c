#include "main.h"

/**
 * find_b_cmd - function to find the builtins commands
 * @sh_data: data
 * Return: return 1
 */
int find_b_cmd(data_container *sh_data)
{
	int (*built_in)(data_container *sh_data);

	if (sh_data->args[0] == NULL)
		return (1);

	built_in = obtain_builtin(sh_data->args[0]);

	if (built_in != NULL)
		return (built_in(sh_data));

	return (cmd_exec(sh_data));
}
