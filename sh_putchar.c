#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On error, -1 is returned, and errno is set appropriately.
 * Description: Function to print characters
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
