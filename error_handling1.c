#include "shell.h"


/**
 * system_environment_error - Handles errors related to env.
 *
 * @data: contains important info
 *
 * Return: Message indicating the error
 */
char *system_environment_error(data_container *data)
{
	int len;
	char *err, *ver, *message;

	ver = aux_itoa(data->counter);
	message = ": Unable to add/remove from the environment\n";
	len = _strlen(data->av[0]) + _strlen(ver);
	len += _strlen(data->args[0]) + _strlen(message) + 4;
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
	_strcat(err, message);
	_strcat(err, "\0");
	free(ver);

	return (err);
}
/**
 * route_126_error_alert - error message for route
 * and access revocation failure
 *
 * @data: Important data
 *
 * Return: String of an error.
 */
char *route_126_error_alert(data_container *data)
{
	int len;
	char *ver, *err;

	ver = aux_itoa(data->counter);
	len = _strlen(data->av[0]) + _strlen(ver) + _strlen(data->args[0]) + 24;
	err = malloc(sizeof(char) * (len + 1));
	if (err == NULL)
	{
		free(ver);
		return (NULL);
	}
	_strcpy(err, data->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver);
	_strcat(err, ": ");
	_strcat(err, data->args[0]);
	_strcat(err, ": access revoked\n");

	free(ver);
	return (err);
}
