#include "shell_header.h"

/**
 * get_path - function finds the PATH value of the enviroment
 * @env: variable that contains enviroment variables
 * Return: an array of the files in the PATH
 */
char **get_path(char **env)
{
	char **patharray, *temp, *hold, *path = "PATH=";
	const char *colon = ": =";
	int count, count2, inputSize = 20, sizearray = 0;

	patharray = malloc(inputSize * sizeof(char *));
	if (patharray == NULL)
	{
		exit(99);
	}

	for (count = 0; env[count] != NULL; count++)
	{
		for (count2 = 0; count2 < 5; count2++)
		{
			if (path[count2] != env[count][count2])
			{
				break;
			}
		}
		if (count2 == 5)
		{
			break;
		}
	}
	hold = _strdup(env[count]);
	temp = strtok(hold, colon);
	temp = strtok(NULL, colon);

	count = 0;
	while (temp != NULL)
	{
		patharray[count] = _strdup(temp);
		count++;
		sizearray++;
		temp = strtok(NULL, colon);
	}
	patharray[count] = NULL;
	free(hold);

	return (patharray);
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
 * _strdup - function duplicates a string
 * @str: string to be copied
 * Return: copied string
 */
char *_strdup(char *str)
{
	char *copiedString;
	int count = 0, arrayLength = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	for (count = 0; str[count] != '\0'; count++)
	{
		arrayLength++;
	}

	copiedString = malloc(sizeof(char) * (arrayLength + 1));

	if (copiedString == NULL)
	{
		return (NULL);
	}

	for (count = 0; str[count] != '\0'; count++)
	{
		copiedString[count] = str[count];
	}
	copiedString[count] = '\0';

	return (copiedString);
}

