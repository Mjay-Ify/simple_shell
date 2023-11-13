#include "shell#.h"

/**
 *cd_dot_get - to changes to the parent directory
 *
 * @data: data relevant (environment_variable)
 *
 * Return: nothing
 */
void cd_dot_get(data_container *data)
{
	char current_path[PATH_MAX];
	char *target_dir, *copy_current_path, *tokenized_path;

	getcwd(current_path, sizeof(current_path));
	copy_current_path = custom_strdup(current_path);
	custom_set_env("OLDPWD", copy_current_path, data);
	target_dir = data->args[1];
	if (custom_strcmp(".", target_dir) == 0)
	{
		custom_set_env("PWD", copy_current_path, data);
		free(copy_current_path);
		return;
	}
	if (custom_strcmp("/", copy_current_path) == 0)
	{
		free(copy_current_path);
		return;
	}
	tokenized_path = copy_current_path;
	custom_rev_string(tokenized_path);
	tokenized_path = _strtok(tokenized_path, "/");
	if (tokenized_path != NULL)
	{
		tokenized_path = custom_strtok(NULL, "\0");

		if (tokenized_path != NULL)
			custom_rev_string(tokenized_path);
	}
	if (tokenized_path != NULL)
	{
		chdir(tokenized_path);
		custom_set_env("PWD", tokenized_path, data);
	}
	else
	{
		chdir("/");
		custom_set_env("PWD", "/", data);
	}
	data->status = 0;
	free(copy_current_path);
}


/**
 * cd_to_get - to changes to a directory given
 * by the user
 *
 * @data: data relevant (directories)
 * Return: void
 */
void cd_to_get(data_container *data)
{
	char current_path[PATH_MAX];
	char *target_dir, *copy_current_path, *copy_target_dir;

	getcwd(current_path, sizeof(current_path));
	copy_current_path = custom_strdup(current_path);
	custom_set_env("OLDPWD", copy_current_path, data);

	target_dir = data->args[1];
	if (chdir(target_dir) == -1)
	{
		obtain_error(data, 2);
		return;
	}

	copy_target_dir = custom_strdup(target_dir);
	custom_set_env("PWD", copy_target_dir, data);

	free(copy_current_path);
	free(copy_target_dir);

	data->status = 0;
	chdir(target_dir);
}

/**
 * cd_previous_get - to changes to the previous directory
 *
 * @data: data relevant (environ)
 * Return: void
 */
void cd_previous_get(data_container *data)
{
	char current_path[PATH_MAX];
	char *previous_pwd, *old_pwd, *copy_current_path, *copy_old_pwd;

	getcwd(current_path, sizeof(current_path));
	copy_current_path = custom_strdup(current_path);
	custom_set_env("OLDPWD", copy_current_path, data);

	old_pwd = custom_getenv("OLDPWD", data->_environment_variable);

	if (old_pwd == NULL)
		copy_old_pwd = copy_current_path;
	else
		copy_old_pwd = custom_strdup(old_pwd);

	custom_set_env("OLDPWD", copy_current_path, data);

	if (chdir(copy_old_pwd) == -1)
		custom_set_env("PWD", copy_current_path, data);
	else
		custom_set_env("PWD", copy_old_pwd, data);

	previous_pwd = custom_getenv("PWD", data->_environment_variable);

	write(STDOUT_FILENO, previous_pwd, custom_strlen(previous_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(copy_current_path);
	if (old_pwd)
		free(copy_old_pwd);

	data->status = 0;
	chdir(previous_pwd);
}

/**
 * cd_to_home_get - to changes to home directory
 *
 * @data: data relevant (environmemt_variable)
 * Return: nothing
 */
void cd_to_home_get(data_container *data)
{
	char *previous_pwd, *home_directory;
	char current_path[PATH_MAX];

	getcwd(current_path, sizeof(current_path));
	previous_pwd = custom_strdup(current_path);

	home_directory = custom_getenv("HOME", data->_environment_variable);

	if (home_directory == NULL)
	{
		custom_set_env("OLDPWD", previous_pwd, data);
		free(previous_pwd);
		return;
	}
	if (chdir(home_directory) == -1)
	{
		obtain_error(data, 2);
		free(previous_pwd);
		return;
	}

	custom_set_env("OLDPWD", previous_pwd, data);
	custom_set_env("PWD", home_directory, data);
	free(previous_pwd);
	data->status = 0;

}
