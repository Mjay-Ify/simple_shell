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

	ver = intToStr(data->counter);
	message = ": Unable to add/remove from the environment\n";
	len = custom_strlen(data->argv[0]) + custom_strlen(ver);
	len += custom_strlen(data->args[0]) + custom_strlen(message) + 4;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver);
		return (NULL);
	}

	custom_strcpy(err, data->av[0]);
	custom_strcat(err, ": ");
	custom_strcat(err, ver);
	custom_strcat(err, ": ");
	custom_strcat(err, data->args[0]);
	custom_strcat(err, message);
	custom_strcat(err, "\0");
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
	len = custom_strlen(data->av[0]) + custom_strlen(ver)
		+ custom_strlen(data->args[0]) + 24;
	err = malloc(sizeof(char) * (len + 1));
	if (err == NULL)
	{
		free(ver);
		return (NULL);
	}
	custom_strcpy(err, data->argv[0]);
	custom_strcat(err, ": ");
	custom_strcat(err, ver);
	custom_strcat(err, ": ");
	custom_strcat(err, data->args[0]);
	custom_strcat(err, ": access revoked\n");
	custom_strcat(err, "\0");
	free(ver);

	return (err);
}
