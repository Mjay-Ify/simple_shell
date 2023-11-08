#include "shell.h"

/**
 * replace_char - To replace | and & for non-printed chars
 * @insert: inserted string
 * @bool: type of replace
 * Return: the replaced string
 */

char *replace_char(char *insert, int bool)
{
	int n;

	if (bool == 0)
	{
		for (n = 0; insert[n]; n++)
		{
			if (insert[n] == '|')
			{
				if (insert[n + 1] != '|')
					insert[n] = 16;
				else
					n++;
			}

			if (insert[n] == '&')
			{
				if (insert[n + 1] != '&')
					insert[n] = 12;
				else
					n++;
			}
		}
	}
	else
	{
		for (n = 0; insert[n]; n++)
		{
			insert[n] = (insert[n] == 16 ? '|' : insert[n]);
			insert[n] = (insert[n] == 12 ? '&' : insert[n]);
		}
	}
	return (insert);
}

/**
 * add_separators - add separators & command lines in the lists
 * @sep_head: head of the  separator list
 * @line_head: head of the command lines list
 * @insert: inserted string
 */
void add_separators(separator_list **sep_head, c_line_list **line_head, char *insert)
{
	int n;
	char *c_line;

	insert = replace_char(insert, 0);

	for (n = 0; insert[n]; n++)
	{
		if (input[n] == ';')
			add_sep_node_end(sep_head, insert[n]);

		if (insert[n] == '|' || insert[n] == '&')
		{
			add_sep_node_end(sep_head, insert[n]);
			n++;
		}
	}

	c_line = _strtok(insert, ";|&");
	do {
		c_line = replace_char(line, 1);
		add_line_node_end(line_head, c_line);
		c_line = _strtok(NULL, ";|&");
	} while (c_line != NULL);
}

/**
 * next_line - function to proceed to the next command line stored
 * @sep_list: separator list
 * @line_list: command line list
 * @datash: data structure
 */
void next_line(sep_list **separator_list, c_line_list **line_list, data_container *sh_data)
{
	int s_loop;
	separator_list *sep_ls;
	c_line_list *line_ls;

	s_loop = 1;
	sep_ls = *sep_list;
	line_ls = *line_list;

	while (sep_ls != NULL && s_loop)
	{
		if (sh_data->status == 0)
		{
			if (sep_ls->sep == '&' || sep_ls->sep == ';')
				s_loop = 0;
			if (sep_ls->sep == '|')
				line_ls = line_ls->nxt, sep_ls = sep_ls->nxt;
		}
		else
		{
			if (sep_ls->sep == '|' || sep_ls->sep == ';')
				s_loop = 0;
			if (sep_ls->sep == '&')
				line_ls = line_ls->nxt, sep_ls = sep_ls->nxt;
		}
		if (sep_ls != NULL && !s_loop)
			sep_ls = sep_ls->nxt;
	}

	*sep_list = sep_ls;
	*line_list = line_ls;
}

/**
 * crack_cmd - function to divide command line by the separators ;, | and &, and executes them
 * @sh_data: shell data structure
 * @insert: inserted string
 * Return: 0 to quit, 1 to proceed
 */
int crack_cmd(data_container *sh_data, char *insert)
{

	separator_list *sep_head, *sep_list;
	c_line_list *line_head, *line_list;
	int sl_loop;

	sep_head = NULL;
	line_head = NULL;

	add_separator(&sep_head, &line_head, insert);

	sep_list = sep_head;
	line_list = line_head;

	while (line_list != NULL)
	{
		sh_data->insert = line_list->line;
		sh_data->args = split_line(sh_data->insert);
		sl_loop = exec_line(sh_data);
		free(sh_data->args);

		if (sl_loop == 0)
			break;

		next_line(&sep_list, &line_list, sh_data);

		if (list_l != NULL)
			line_list = line_list->nxt;
	}

	free_sep_list(&sep_head);
	free_line_list(&line_head);

	if (sl_loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - function to tokenizes the input string
 * @input: input string.
 * Return: string splitted.
 */
char **crack_line(char *insert)
{
	size_t bt_size;
	size_t n;
	char **toks;
	char *tok;

	bt_size = TOK_BUFFERSIZE;
	toks = malloc(sizeof(char *) * (bt_size));
	if (toks == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	tok = _strtok(insert, TOKEN_SEP);
	tok[0] = tok;

	for (n = 1; tok != NULL; n++)
	{
		if (n == bt_size)
		{
			bt_size += TOKEN_BUFFERSIZE;
			toks = _reallocdp(toks, n, sizeof(char *) * bt_size);
			if (toks == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		tok = _strtok(NULL, TOKEN_SEP);
		toks[i] = tok;
	}

	return (toks);
}
