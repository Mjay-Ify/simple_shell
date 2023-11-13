#include "shell.h"

/**
 * _iscdire - To check ":" is in the current dire
 * @way: type of char pointer
 * @n: type int pointer of index
 * Return: 1 if the way is searchable in the cd, 0 otherwise
 */
int _iscdire(char *way, int *n)
{
	if (way[*n] == ':')
		return (1);

	while (way[*n] != ':' && way[*n])
		*n += 1;

	if (way[*n])
		*n += 1;

	return (0);
}

/**
 * loc_cmd - To locates command
 * @n_cmd: name of command
 * @envn: environment var
 * Return: location of command
 */

char *loc_cmd(char *n_cmd, char **envn)
{
	char *way, *ptr_way, *token_way, *dirs;
	int len_dirs, len_cmds, n;
	struct stat st;

	path = obtain_envn("PATH", envn);
	if (way)
	{
		ptr_way = _strdup(way);
		len_cmds = _strlen(n_cmd);
		token_way = _strtok(ptr_way, ":");
		n = 0;
		while (token_way != NULL)
		{
			if (_iscdire(way, &n))
				if (stat(n_cmd, &st) == 0)
					return (n_cmd);
			len_dirs = _strlen(token_way);
			dirs = malloc(len_dirs + len_cmds + 2);
			_strcpy(dirs, token_way);
			_strcat(dirs, "/");
			_strcat(dirs, cmd);
			_strcat(dirs, "\0");
			if (stat(dirs, &st) == 0)
			{
				free(ptr_way);
				return (dirs);
			}
			free(dirs);
			token_way = _strtok(NULL, ":");
		}
		free(ptr_way);
		if (stat(cmd, &st) == 0)
			return (n_cmd);
		return (NULL);
	}
	if (n_cmd[0] == '/')
		if (stat(n_cmd, &st) == 0)
			return (n_cmd);
	return (NULL);
}

/**
 * is_exec - To checks if it is an executable
 * @sh_data: data
 * Return: 0 if is not an executable, other number if it is
 */
int is_exec(data_container *sh_data)
{
	struct stat st;
	int n;
	char *insert;

	insert = sh_data->args[0];
	for (n = 0; insert[n]; n++)
	{
		if (insert[n] == '.')
		{
			if (insert[b + 1] == '.')
				return (0);
			if (insert[i + b] == '/')
				continue;
			else
				break;
		}
		else if (insert[n] == '/' && n != 0)
		{
			if (insert[i + 1] == '.')
				continue;
			n++;
			break;
		}
		else
			break;
	}
	if (n == 0)
		return (0);

	if (stat(insert + n, &st) == 0)
	{
		return (n);
	}
	obtain_error(sh_data, 127);
	return (-1);
}

/**
 * verify_cmd_err - To check if the user has permissions to access
 * @dirs: dir of destination
 * @sh_data: data structure
 * Return: 1 if there is error, 0 if not
 */
int verify_cmd_err(char *dirs, data_container *sh_data)
{
	if (dirs == NULL)
	{
		obtain_error(sh_data, 127);
		return (1);
	}

	if (_strcmp(sh_data->args[0], dirs) != 0)
	{
		if (access(dirs, X_OK) == -1)
		{
			obtain_error(sh_data, 126);
			free(dirs);
			return (1);
		}
		free(dirs);
	}
	else
	{
		if (access(sh_data->args[0], X_OK) == -1)
		{
			obtain_error(sh_data, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * exe_command - function to execute command lines
 * @datash: data
 * Return: 1 on success
 */
int exe_command(data_container *sh_data)
{
	pid_t pid;
	pid_t wpid;
	int stat, exe;
	char *dirs;
	(void) wpid;

	exe = is_exec(sh_data);
	if (exe == -1)
		return (1);
	if (exe == 0)
	{
		dirs = loc_cmd(sh_data->args[0], sh_data->_environ);
		if (verify_cmd_err(dirs, sh_data) == 1)
			return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (exe == 0)
			dirs = loc_cmd(sh_data->args[0], sh_data->_environ);
		else
			dirs = sh_data->args[0];
		execve(dirs + exe, sh_data->args, sh_data->_environ);
	}
	else if (pid < 0)
	{
		perror(sh_data->av[0]);
		return (1);
	}
	else
	{
		do {
			wpid = waitpid(pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}

	sh_data->status = stat / 256;
	return (1);
}
