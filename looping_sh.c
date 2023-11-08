#include "shell.h"


/**
 * del_comment - function to deletes comments from the inserted
 * @insert: inserted string
 * Return: insert without the comments
 */
char *del_comment(char *insert)
{
	int n, nxt;

	nxt = 0;
	for (n = 0; insert[n];n++)
	{
		if (insert[n] == '#')
		{
			if (n == 0)
			{
				free(insert);
				return (NULL);
			}

			if (insert[n - 1] == ' ' || insert[n - 1] == '\t' || insert[n - 1] == ';')
				nxt = n;
		}
	}

	if (nxt != 0)
	{
		insert = _realloc(insert, n, nxt + 1);
		insert[nxt] = '\0';
	}

	return (insert);
}

/**
 * looping_sh - for looping of shell
 * @sh_data: data relevant are av, insert, args
 */
void looping_sh(data_container *sh_data)
{
	int loop_sh, n;
	char *insert;

	loop_sh = 1;
	while (loop_sh == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&n);
		if (n != -1)
		{
			insert = del_comment(insert);
			if (insert == NULL)
				continue;

			if (check_syntax_error(sh_data, insert) == 1)
			{
				sh_data->stat = 2;
				free(insert);
				continue;
			}
			insert = rep_var(insert, sh_data);
			loop = crack_cmd(sh_data, insert);
			sh_data->count += 1;
			free(insert);
		}
		else
		{
			loop_sh = 0;
			free(insert);
		}
	}
}
