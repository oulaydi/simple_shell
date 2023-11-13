#include "shell.h"

/**
* free_lmlawi - frees an array of strings
* @array: array of strings
*/


void free_lmlawi(char **array)
{
	int i = 0;

	if (!array)
		return;
	for (; array[i]; i++)
		free(array[i]);
	free(array);
}
