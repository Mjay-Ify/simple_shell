#include "shell.h"

/**
 * custom_strdup - Allocates memory for a new string and copies the content..
 * @str: The input string to be dupicated
 * Return: a pointer to the duplicated string on success
 */

char *custom_strdup(const char *str)
{
	char *new_node;
	size_t length;

	length = _strlen(str);
	new_node = malloc(sizeof(char) * (length + 1));
	if (new_node == NULL)
		return (NULL);
	custom_memcpy(new_node, str, length + 1);
	return (new_node);
}

/**
 * custom_strlen - computes the length of a string.
 * @str: Input string.
 * Return: Always 0.
 */

int custom_strlen(const char *str)
{
	int length;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * hasDelimiter - compare chars of strings
 * @s: input string.
 * @delimiter: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */

int hasDelimiter(char s[], const char *delimiter)
{
	for (int i  = 0; s[i]; i++)
	{
		for (int j = 0; delimiter[j]; j++)
		{
			if (s[i] == delimiter[j])
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * custom_strtok - Splits a string by a delimiter.
 * @input_str: input string.
 * @delimiter: delimiter string.
 *
 * Return: Pointer to the next token or NULL if no more tokens
 */

char *custom_strtok(char input_str[], const char *delimiter)
{
	static char *current_token, *str_end;
	char *token_start;
	unsigned int i = 0;
	_Bool bool = false;

	if (input_str != NULL)
	{
		if (hasDelimiter(input_str, delimiter))
			return (NULL);
		current_token = input_str; /*Store first address*/
		i = custom_strlen(input_str);
		str_end = &input_str[i]; /*Store last address*/
	}
	token_start = current_token;
	if (token_start == str_end) /*Reaching the end*/
		return (NULL);

	bool = false;
	while (*current_token)
	{
		/*Breaking loop finding the next token*/
		if (curent_token != current_token)
			if (*current_token && *(current_token - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		i = 0;
		while (delimiter[i])
		{
			if (*current_token == delimiter[i])
				*current_token = '\0';
				if (curent_token == token_start)
					token_start++;
				break;
			}
			i++;
		}
		if (bool == false == 0 && *current_token) /*Str != Delim*/
			bool = true;
		current_token++;
	}
	if (bool == false) /*Str == Delim*/
		return (NULL);
	return (token_start);
}

/**
 * is_number - Checks if string passed is a number
 *
 * @str: input string
 * Return: 1 if string is a number. otherwise 0.
 */
int is_number(const char *str)
{

	for (unsigned int i = 0; str[i] i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}
}