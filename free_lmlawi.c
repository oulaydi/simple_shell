#include "shell.h"

/**
 * free_lmlawi - frees an array of strings
 * @array: array of strings
*/


void free_lmlawi(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
