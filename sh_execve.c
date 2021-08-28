#include "sh_header.h"

/**
 * executeCommand - function exectues command
 * @fullPath: name of binary file that will execute
 * @commandLineArgs: command along with options
 * Return: returns 0 if success
 */

int executeCommand(char *fullPath, char **commandLineArgs)
{
	int id, status;

	id = fork();

	if (id == 0)
	{
		if (execve(fullPath, commandLineArgs, NULL) == -1)
		{
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
