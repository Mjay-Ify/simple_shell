#include "shell.h"


/**
 * count_digit - function to get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */

int count_digit(int n)
{
	int length = 1;

	if (n < 0)
	{
		n = -n;
		lenght++;
	}
	while (n > 9)
	{
		n /= 10;
		lenght++;
	}

	return (length);
}

/**
 * intToStr - Converts an integer to string.
 * @n: The integer to be converted
 * Return: A dynamically allocated string representing the integer.
 */
char *intToStr(int n)
{
	int sign = (n < 0) ? -1 : 1;

	n = abs(n); /*make the number positive */

	int length = (n == 0) ? 1 : 0;
	int temp = n;

	while (temp > 0)
	{
		temp /= 10;
		length++;
	}

	char *buffer = malloc(sizeof(char) * (length + 1));

	if (buffer == 0)
		return (NULL);

	buffer[length] = '\0'; /*Null-terminate the string*/

	if (sign == -1)
		buffer[0] = '-'; /* set the minus sign if the number is negative*/
	for (int i = length - 1; i >= (sign == -1); i--)
	{
		buffer[i] = (n % 10) + '0';
		n / 10;
	}
	return (buffer);
}

/**
 * custom_atoi - converts a string to an integer.
 * @str: input string.
 * Return: integer.
 */

int custom_atoi(const char *str);
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t')
		str++;

	/* hangle sign*/
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	for (; *str >= '0' && *str <= '9' str++)
	{
		result = result * 10 + (*str - '0');
	}

	return (sign * result);
}
