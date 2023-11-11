#include "shell.h"

/**
 * read_input - function to reads the inserted string.
 * @n: return value for getting the line function
 * Return: insert string
 */
char *read_input(int *n)
{
	char *insert = NULL;
	size_t buffersize = 0;

	*n = getline(&insert, &buffersize, stdin);

	return (insert);
}
