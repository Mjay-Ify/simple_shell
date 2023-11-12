#include "shell.h"

/**
 * is_current_dir - Checks if the character at index i in the path is ':'
 * @path: type char pointer
 * @i: type int pointer of index
 * Return:  1 if the path character is ':', 0 otherwise
 */
int is_current_dir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
		*i += 1;

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * custom_which - To locates a command
 * @command: command name
 * @environment_variable: environment variable
 * Return: location of the command.
 */

char *custom_which(char *command, char **environment_variable)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = custom_getenv("PATH", environment_variable);
	if (path)
	{
		ptr_path = custom_strdup(path);
		len_cmd = custom_strlen(command);
		token_path = custom_strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_current_dir(path, &i))
				if (stat(command, &st) == 0)
					return (command);
			len_dir = custom_strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			custom_strcpy(dir, token_path);
			custom_strcat(dir, "/");
			custom_strcat(dir, cmd);
			custom_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = custom_strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(command, &st) == 0)
			return (command);
		return (NULL);
	}
	if (command[0] == '/')
		if (stat(command, &st) == 0)
			return (command);
	return (NULL);
}

/**
 * custom_is_executable - To checks if is an executable
 * @data: data format
 * Return: 0 if is not an executable, other number if it does
 */
int custom_is_executable(data_container *data)
{
	struct stat st;
	int i;
	char *insert;

	insert = data->args[0];
	for (i = 0; insert[i]; i++)
	{
		if (insert[i] == '.')
		{
			if (insert[i + 1] == '.')
				return (0);
			if (insert[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (insert[i] == '/' && i != 0)
		{
			if (insert[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(insert + i, &st) == 0)
	{
		return (i);
	}
	obtain_error(data, 127);
	return (-1);
}

/**
 * verify_error_command - To checks if user has permissions to access
 * @dir: destination's directory
 * @data: data structure
 * Return: 1 if there is an error, 0 if not
 */
int verify_error_command(char *dir, data_container *data)
{
	if (dir == NULL)
	{
		obtain_error(data, 127);
		return (1);
	}

	if (custom_strcmp(data->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			obtain_error(data, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(data->args[0], X_OK) == -1)
		{
			obtain_error(data, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * command_execute - Executes command lines
 * @data: data that are relevant
 * Return: on success 1
 */
int command_execute(data_container *data)
{
	pid_t pd;
	pid_t wpd;
	int state, execute;
	char *dir;
	(void) wpd;

	execute = _custom_is_executable(data);
	if (execute == -1)
		return (1);
	if (execute == 0)
	{
		dir = custom_which(data->args[0], data->environment_variable);
		if (verify_error_command(dir, data) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (execute == 0)
			dir = custom_which(data->args[0], data->environment_variable);
		else
			dir = data->args[0];
		execve(dir + execute, data->args, data->environment_variable);
	}
	else if (pd < 0)
	{
		perror(data->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	data->status = state / 256;
	return (1);
}
