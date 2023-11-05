#include "shell.h"

/**
 * strcat_custom - Concatenates a message with custom behavior.
 *
 * @data: data container
 * @message: message to be shown
 * @err: Message going out
 * @ver: Lines to count
 *
 * Return: error message
 */
char *strcat_custom(data_container *data, char *message, char *err, char *ver)
{
	char *error_flag = (char *)malloc(3);

	_strcpy(err, data->av[0]);
	_strcat(error, ": ");
	_strcat(err, ver);
	_strcat(err, ": ");
	_strcat(err, data->args[0]);
	_strcat(err, message);
	error_flag[0] = '-';
	error_flag[1] = (data->args[1][0] == '-') ? data->args[1][1] : '\0';
	error_flag[2] = '\0';
	_strcat(err, error_flag);
	free(error_flag);
	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * fetch_error_custom - error message
 * @data: relevant data or file.
 * Return: Inputs that are mesaages.
 */
char *fetch_error_custom(data_container *data)
{
	int len, id;
	char *err, *ver, *message;

	ver = aux_itoa(data->counter);
	message = (data->args[1][0] == '-') ?
		": error option " :
		": can't custom to ";
	id = (data->args[1][0] == '-') ? 2 : _strlen(data->args[1]);

	len = _strlen(data->av[0]) + _strlen(data->args[0])
	+ _strlen(ver) + _strlen(message) + id + 5;
	err = (char *)malloc(sizeof(char) * (len + 1));
	if (err == NULL)
	{
		free(ver);
		return (NULL);
	}

	err = strcat_custom(data, message, err, ver);
	free(ver);

	return (err);
}

/**
 * missing_file_error - Error mssg for commands missing.
 * @data: Important file
 * Return: Messages that shows error
 */
char *missing_file_error(data_container *data)
{
	int len;
	char *err, *ver;

	ver = aux_itoa(data->counter);
	len = _strlen(data->av[0]) + _strlen(ver);
	len += _strlen(data->args[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver);
		return (NULL);
	}
	_strcpy(err, data->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver);
	_strcat(err, ": ");
	_strcat(err, data->args[0]);
	_strcat(err, ": missing\n");
	_strcat(err, "\0");
	free(ver);
	return (err);
}

/**
 * shell_terminate_error- Error message for exit in get_exit
 * @data: file that are relevant
 * Return: Error message
 */
char *shell_terminate_error(data_container *data)
{
	int len;
	char *err;
	char *ver;

	ver = aux_itoa(data->counter);
	len = _strlen(data->av[0]) + _strlen(ver);
	len += _strlen(data->args[0]) + _strlen(data->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver);
		return (NULL);
	}
	_strcpy(err, data->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver);
	_strcat(err, ": ");
	_strcat(err, data->args[0]);
	_strcat(err, ": error number: ");
	_strcat(err, data->args[1]);
	_strcat(err, "\n\0");
	free(ver);

	return (err);
}
