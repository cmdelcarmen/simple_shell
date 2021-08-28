#include "shell_header.h"

/**
 * input - function gets input from user
 * @patharray: path array
 * Return: commandLineArgs
 */
char **input(char **patharray)
{
	ssize_t length, allSpaces;
	size_t inputSize = 50;
	char *usrinput = NULL, *newInput = NULL;

	prompt();
	length = getline(&usrinput, &inputSize, stdin);
	if (length == EOF || (length == 1 && (isatty(STDIN_FILENO) == 0)))
	{
		return (handlesNullInput(usrinput));
	}
	if (length == 1 && (isatty(STDIN_FILENO) == 1))
	{
		while (length == 1)
		{
			prompt();
			length = getline(&usrinput, &inputSize, stdin);
		}
	}
	usrinput[length - 1] = '\0';
	allSpaces = checkIfInputAllSpaces(usrinput);

	while (allSpaces == 1)
	{
		prompt();
		length = getline(&usrinput, &inputSize, stdin);
		if (length == EOF)
			return (handlesNullInput(usrinput));
		
		usrinput[length - 1] = '\0';
		allSpaces = checkIfInputAllSpaces(usrinput);
	}
	if ((checkIfPath(usrinput)) == 1)
	{
		newInput = pathInput(usrinput, patharray);
		if (newInput == NULL)
		{
			free(newInput);
			return (getArray(usrinput));
		}
		return (getArray(newInput));
	}
	free(newInput);
	return (getArray(usrinput));
}

/**
 * getArray - function converts user input into an array
 * @usrinput: user input
 * Return: commandLineArgs
 */
char **getArray(char *usrinput)
{
	int count, count2, index1 = 0, sizeOfArr = 0;
	char **commandLineArgs;

	sizeOfArr = numberOfElementsInArray(usrinput);/*counts the args entered*/
	commandLineArgs = malloc(sizeof(commandLineArgs) * (sizeOfArr + 1));
	if (commandLineArgs == NULL)
	{
		free(usrinput);
		return (NULL);
	}
	for (count = 0; count < sizeOfArr; count++) /*allocate mem for double ptr*/
	{
		commandLineArgs[count] = malloc(sizeof(char) * 100);

		if (commandLineArgs[count] == NULL)
		{
			for (count -= 1; count >= 0; count--)
			{
				free(commandLineArgs[count]);
			}
			free(commandLineArgs);
			return (NULL);
		}
	}
	index1 = moveIndex(usrinput); /*handles spaces at beginning*/
	for (count = 0; (count < 100) && (usrinput[index1] != '\0'); count++)
	{
		for (count2 = 0; usrinput[index1] != 32
			&& usrinput[index1] != '\0'; count2++)
		{
			commandLineArgs[count][count2] = usrinput[index1];
			index1++; /*initiazlie arr to values from input EXCLUDING spaces*/
		}
		commandLineArgs[count][count2] = '\0'; /*null at end of string*/
		while (usrinput[index1] == 32)
			index1++; /*handles extra spaces between arguments*/
	}
	commandLineArgs[count] = NULL; /*marks end of 2D array*/
	free(usrinput);
	return (commandLineArgs);
}

/**
 * _strcmp - function compares two strings
 * @s1: string to compare
 * @s2: string to compare
 * Return: 0 if strings are the same, -1 if not
 */
int _strcmp(char *s1, char *s2)
{
	int count;

	for (count = 0; s1[count] != '\0' || s2[count] != '\0'; count++)
	{
		if (s1[count] != s2[count])
			return (-1);
	}

	return (0);
}
