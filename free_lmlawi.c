#include "shell.h"

/**
 * free_lmlawi - frees an array of strings
 * @array: array of strings
*/


void free_lmlawi(char **array)
{
	int i = 0;

	if (array == NULL)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
	}
	free(array[i]);
	free(array);
}

/**
 * call_env - call the env_print function
 * @arr: array
 * @str: string (env)
*/

void call_env(char **arr, char *str)
{
	if (_strcmp(arr[0], str) == 0)
	{
		env_print();
		free(arr);
	}
}
