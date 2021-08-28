#include "shell_header.h"

/**
 * exitString - function handles exit command
 * @usrinput: user input
 * Return: 0 if it is exit, 1 if it is not
 */
int exitString(char *usrinput)
{
	int index1, count;
	char *temp;

	index1 = moveIndex(usrinput);

	temp = malloc(sizeof(char) * 5);

	for (count = 0; usrinput[index1] != '\0' || count < 4; count++)
	{
		temp[count] = usrinput[index1];
		index1++;
	}
	temp[count] = '\0';


	if ((_strcmp("exit", temp)) == 0)
	{
		free(temp);
		return (0);
	}
	else
	{
		free(temp);
		return (1);
	}
}
