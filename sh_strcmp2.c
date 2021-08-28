#include "shell_header.h"

/**
 * _strcmp2 - function compares input with directories
 * @s1: string to compare
 * @s2: string to compare
 * Return: 0 if strings are the same, -1 if not
 */
int _strcmp2(char *s1, char *s2)
{
	int count;

	for (count = 0; s2[count] != '\0'; count++)
	{
		if (s1[count] == s2[count])
		{
			;
		}
		else
		{
			if (s2[count] == '/' && s1[count] == '\0' && s2[count + 1] == '\0')
			{
				return (0);
			}
			return (-1);
		}
	}
	return (0);
}
/**
 * get_c - handle ^C
 *
 * @sig: the signal
 */

void get_c(int sig)
{
	write(STDOUT_FILENO, "\n$ ", 3);
	signal(sig, get_c);
}
