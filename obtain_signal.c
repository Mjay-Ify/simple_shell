#include "shell.h"

/**
 * obtain_signal - function that handle the crtl + c call in prompt
 * @sig_val: the Signal handler
 */

void obtain_signal(int sig_val)
{
	(void)sig_val;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
