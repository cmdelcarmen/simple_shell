#include "sh_header.h"

/**
 * freeDoublePointers - function frees double pointers
 * @pointer: double pointer passed to function
 */
void freeDoublePointers(char **pointer)
{
	int count, numOfPtrsToFree = 0;

	for (count = 0; pointer[count] != NULL; count++)
	{
		numOfPtrsToFree++;
	}

	for (; numOfPtrsToFree >= 0; numOfPtrsToFree--)
	{
		free(pointer[numOfPtrsToFree]);
	}

	free(pointer);
}

/**
 * printDoubleArray - function prints out double arrays
 * @pointer: pointer passed
 */
void printDoubleArray(char **pointer)
{
	int count, count2;

	for (count = 0; pointer[count] != NULL; count++)
	{
		for (count2 = 0; pointer[count][count2] != '\0'; count2++)
		{
			_putchar(pointer[count][count2]);
		}
		_putchar('\n');
	}
}

