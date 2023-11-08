#include "shell.h"

/**
 * verify_envn - to verify if the typed variable is an envn var
 * @head: the linked list head
 * @insert: inserted string
 * @sh_data: structure of data
 */
void verify_envn(r_var **head, char *insert, data_container *sh_data)
{
	int rows, col, n, value;
	char **envn;

	envn = sh_data->_environ;
	for (rows = 0; envn[rows]; rows++)
	{
		for (n = 1, col = 0; envn[rows][col]; col++)
		{
			if (envn[rows][col] == '=')
			{
				value = _strlen(envn[rows] + col + 1);
				add_rvar_node(head, n, envn[rows] + col + 1, value);
				return;
			}

			if (insert[n] == envn[rows][col])
				n++;
			else
				break;
		}
	}

	for (n = 0; insert[n]; n++)
	{
		if (insert[n] == ' ' || insert[n] == '\t' || insert[n] == ';' || insert[n] == '\n')
			break;
	}

	add_rvar_node(head, n, NULL, 0);
}

/**
 * verify_var - to detect if the typed var is $$ or $?
 * @head: linked list head
 * @insert: insert string
 * @stat: last status of the Shell
 * @sh_data: data struct
 */
int verify_var(r_var **head, char *insert, char *stat, data_container *sh_data)
{
	int n, list, lpid;

	list = _strlen(st);
	lpid = _strlen(sh_data->pid);

	for (n = 0; insert[n]; n++)
	{
		if (insert[n] == '$')
		{
			if (insert[n + 1] == '?')
				add_rvar_node(head, 2, stat, list), n++;
			else if (insert[n + 1] == '$')
				add_rvar_node(head, 2, sh_data->pid, lpid), n++;
			else if (insert[n + 1] == '\n')
				add_rvar_node(head, 0, NULL, 0);
			else if (insert[n + 1] == '\0')
				add_rvar_node(head, 0, NULL, 0);
			else if (insert[n + 1] == ' ')
				add_rvar_node(head, 0, NULL, 0);
			else if (insert[n + 1] == '\t')
				add_rvar_node(head, 0, NULL, 0);
			else if (insert[n + 1] == ';')
				add_rvar_node(head, 0, NULL, 0);
			else
				verify_envn(head, insert + n, sh_data);
		}
	}

	return (n);
}

/**
 * rep_insert - function that replaces string to variables
 * @head: head of linked list
 * @inser: insert string
 * @new_insert: new inserted string to replace
 * @n_len: the new length
 * Return: replaced insert string
 */
char *rep_insert(r_var **head, char *insert, char *new_insert, int n_len)
{
	r_var *index;
	int a, b, n;

	index = *head;
	for (b = a = 0; a < n_len; a++)
	{
		if (insert[b] == '$')
		{
			if (!(index->len_var) && !(index->len_val))
			{
				new_insert[a] = insert[b];
				b++;
			}
			else if (index->len_var && !(index->len_val))
			{
				for (n = 0; n < index->len_var; n++)
					b++;
				a--;
			}
			else
			{
				for (n = 0; n < index->len_val; n++)
				{
					new_insert[a] = index->val[n];
					a++;
				}
				b += (index->len_var);
				a--;
			}
			index = index->next;
		}
		else
		{
			new_insert[a] = insert[b];
			b++;
		}
	}

	return (new_insert);
}

/**
 * replace_var - To call the functions to replace the string into variable
 * @insert: the insert string
 * @sh_data: structure of data
 * Return: replace insert string
 */
char *replace_var(char *insert, data_shell *sh_data)
{
	r_var *head, *index;
	char *stat, *new_insert;
	int o_len, n_len;

	stat = aux_itoa(sh_data->stat);
	head = NULL;
	o_len = verify_var(&head, insert, stat, sh_data);

	if (head == NULL)
	{
		free(stat);
		return (insert);
	}

	index = head;
	n_len = 0;

	while (index != NULL)
	{
		n_len += (index->len_val - index->len_var);
		index = index->next;
	}

	n_len += o_len;
	new_insert = malloc(sizeof(char) * (n_len + 1));
	new_insert[n_len] = '\0';
	new_insert = rep_insert(&head, insert, new_insert, n_len);
	free(insert);
	free(stat);
	free_rvar_list(&head);

	return (new_insert);
}
