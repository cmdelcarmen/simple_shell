#include "sh_header.h"

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
 * prompt - function checks to see if prompt needs to be printed
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		_putchar('$');
		_putchar(' ');
	}

}

/**
 *  pathInput - function modifies user input and returns command
 * without the executable
 * @usrinput: input from user
 * @patharray: path array
 * Return: returns pointer
 */
char *pathInput(char *usrinput, char **patharray)
{
	int count, count2 = 0, index1 = 0, lastBracketIndex = 0, num = 0;
	char *modedUsrInput;
	int matches = 0;

	modedUsrInput = malloc(sizeof(char) * 100);

	index1 = moveIndex(usrinput);

	/*Plus 1 so it does not start at '/'*/
	for (count = index1 + 1; usrinput[count] != '\0'; count++)
	{
		if (usrinput[count] == '/')
		{
			lastBracketIndex = count;
			num++;
		}
	}
	matches = verifyPath(usrinput, patharray);

	if (matches == 0)
	{
		free(modedUsrInput);
		return (usrinput);
	}

	if (usrinput[lastBracketIndex + 1] == '\0' || (num == 0))
	{
		free(modedUsrInput);
		return (usrinput);
	}
	count2 = 0;
	for (count = lastBracketIndex + 1; usrinput[count] != '\0'; count++)
	{
		modedUsrInput[count2] = usrinput[count];
		count2++;
	}
	modedUsrInput[count2] = '\0';

	free(usrinput);
	return (modedUsrInput);
}

/**
 * checkIfInputAllSpaces - function checks to see if input is all spaces
 * @usrinput: user input
 * Return: 0 if it is not all spaces, 1 if it is all spaces
 */
int checkIfInputAllSpaces(char *usrinput)
{
	int count;

	for (count = 0; usrinput[count] != '\0'; count++)
	{
		if (usrinput[count] != 32)
		{
			return (0);
		}
	}
	return (1);
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
 * handlesNullInput - functions checks for NULL input
 * @usrinput: user or file input
 * Return: NULL
 */
char **handlesNullInput(char *usrinput)
{
	free(usrinput);
	return (NULL);
}

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
