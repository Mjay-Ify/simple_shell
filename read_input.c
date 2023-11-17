#include "shell.h"

/**
 * read_input - Reads a line of input from the user.
 * @n: Size of the buffer to store the input.
 * Return: The input string read from the user.
 */
char *read_input(int *n)
{
	char *insert = NULL;
	size_t buffersize = 0;

	*n = obtain_line(&insert, &buffersize, stdin);

	return (insert);
}
