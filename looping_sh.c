#include "shell.h"


/**
 * del_comment - Removes comments from the input string
 * @insert: The input string containing comments.
 * Return: The input string with comment removed
 */
char *del_comment(char *insert)
{
	int n, next;

	next = 0;
	for (n = 0; insert[n]; n++)
	{
		if (insert[n] == '#')
		{
			if (n == 0)
			{
				free(insert);
				return (NULL);
			}

			if (insert[n - 1] == ' ' || insert[n - 1] == '\t' || insert[n - 1] == ';')
				next = n;
		}
	}

	if (next != 0)
	{
		insert = _realloc(insert, n, next + 1);
		insert[next] = '\0';
	}

	return (insert);
}

/**
 * looping_sh - for looping of shell
 * @data: data structure containing relevant information are av,
 * insert, args
 */
void looping_sh(data_container *data)
{
	int loop_sh, n;
	char *insert;

	loop_sh = 1;
	do {
		write(STDIN_FILENO, "^-^ ", 4);
		insert = read_line(&n);
		if (n != -1)
		{
			insert = del_comment(insert);
			if (insert == NULL)
				continue;

			if (check_syntax_error(data, insert) == 1)
			{
				data->status = 2;
				free(insert);
				continue;
			}
			insert = rep_var(insert, data);
			loop_sh = crack_cmd(data, insert);
			data->count += 1;
			free(insert);
		}
		else
		{
			loop_sh = 0;
		}

	} while (loop_sh);
}
