#include "shell_header.h"

/**
 * numberOfElementsInArray - function counts the number of commans/
 * optionsin user input
 * @usrinput: input from user
 * Return: length of the 2D array for user input
 */
int numberOfElementsInArray(char *usrinput)
{
	int count, lengthOfArray = 0;

	for (count = 0; usrinput[count] != '\0'; count++)
	{
		if (usrinput[count] == ' ' && usrinput[count + 1] == '\0')
		{
			return (lengthOfArray);
		}
		if ((usrinput[count] == 32 && usrinput[count + 1] != 32) ||
				(count == 0 && usrinput[count] != 32))
		{
			lengthOfArray++;
		}
	}
	return (lengthOfArray);
}

/**
 * moveIndex - function moves the index up from where we start reading command,
 * if there are extra spaces at beginning of user input
 * @usrinput: input from user
 * Return: the index to start reading command from
 */
int moveIndex(char *usrinput)
{
	int count, index1 = 0;

	for (count = 0; (usrinput[index1] == 32  || usrinput[index1] == '\t')
			&& usrinput[index1] != '\0'; count++)
	{
		index1++;

		if (usrinput[index1] != 32)
		{
			break;
		}
	}

	return (index1);
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
 *checkIfPath - function searches for '/' in order to identify path's entered
 *@usrinput: input from user
 *Return: checkpath
 */
int checkIfPath(char *usrinput)
{
	int count, checkpath = 0;

	for (count = 0; usrinput[count] != '\0'; count++)
	{
		if (usrinput[count] == '/' && usrinput[count + 1] != '\0')
		{
			checkpath = 1;

			return (checkpath);
			/**
			 * newInput = pathInput(usrinput);

			if (newInput == NULL)
			{
				free(newInput);
				return (getArray(usrinput));
			}
			return (getArray(newInput));
			*/
		}
	}
	return (checkpath);
}

/**
 * verifyPath - function checks to see if its and actual
 * PATH directory
 * @usrinput: user input
 * @patharray: array of path
 * Return: 1 or 0
 */
int verifyPath(char *usrinput, char **patharray)
{
	int index1 = 0, lastBracketIndex = 0, matches = 0, count, count2;
	char *pathChecker;

	pathChecker = malloc(sizeof(char) * 50);
	index1 = moveIndex(usrinput);

	for (count = index1 + 1; usrinput[count] != '\0'; count++)
	{
		if (usrinput[count] == '/')
		{
			lastBracketIndex = count;
		}
	}
	count2 = index1;

	for (count = 0; count2 < lastBracketIndex; count++)
	{
		pathChecker[count] = usrinput[count2];
		count2++;
	}
	pathChecker[count] = '\0';

	for (count = 0; patharray[count] != NULL; count++)
	{
		if ((_strcmp(pathChecker, patharray[count])) == 0)
		{
			matches = 1;
			break;
		}
	}
	free(pathChecker);

	if (matches == 1)
		return (1);

	if (matches == 0)
		return (0);

	return (0);
}
