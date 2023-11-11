#include "shell.h"

/**
 * obtain_errors - To call the error according the builtin
 * @sh_data: the structure of the data that contains arg
 * @val: the error value
 * Return: the error
 */
int obtain_errors(data_container *sh_data, int val)
{
	char *err;

	switch (val)
	{
	case -1:
		err = error_env(sh_data);
		break;
	case 126:
		err = error_path_126(sh_data);
		break;
	case 127:
		err = error_not_found(sh_data);
		break;
	case 2:
		if (_strcmp("exit", sh_data->args[0]) == 0)
			err = err_exit_shell(sh_data);
		else if (_strcmp("cd", sh_data->args[0]) == 0)
			err = error_get_cd(sh_data);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	sh_data->stat = val;
	return (val);
}
