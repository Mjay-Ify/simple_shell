#include "shell.h"

/**
 * close_shell - function that closes the shell
 * @shh_data: data
 * Return: 0
 */
int close_shell(data_container *sh_data)
{
	unsigned int status;
	int is_dig, len, b_num;

	if (sh_data->args[1] != NULL)
	{
		status = _atoi(sh_data->args[1]);
		is_dig = _isdigit(sh_data->args[1]);
		len = _strlen(sh_data->args[1]);
		b_num = status > (unsigned int)INT_MAX;
		if (!is_dig || len > 10 || b_num)
		{
			obtain_error(sh_data, 2);
			sh_data->stat = 2;
			return (1);
		}
		sh_data->stat = (status % 256);
	}
	return (0);
}
