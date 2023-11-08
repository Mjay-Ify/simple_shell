#include "shell.h"


/**
 * append_sep_to_end - function to append separator
 * @list: pointer ot the linked list head
 * @seperator: separator charcter (; | &).
 * Return: pointer to the updated list
 */

sep_list *append_sep_to_end(sep_list **list, char seperator)
{
	sep_list *new_node = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new_node->separator = separator;
	new_node->next = NULL;

	if (list == NULL)
		*list = new_node;
	else
	{
		sep_list *temp - *list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*list);
}

/**
 * deallocate_sep_list - function to deallocate memory used by sep_list
 * @list: pointer to the linked list head.
 */

void deallocate_sep_list(sep_list **list)
{
	sep_list *current = *list;
	sep_list *next;

	while (current != NULL)
	{
		next = *current->next;
		free(current);
		*cuurent= next;
	}
	*list = NULL; /*set the head to null after freeing all nodes, */
}

/**
 * add_line_node_end - function to adds command line
 * @head: linked list head
 * @line: command line
 * Return: The head address
 */

line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_line_list - function to free line_list
 * @head: linked list head
 * Return: nothing
 */
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
