#include "shell.h"

/**
* splitting_line - use strtok to split the line
* @line: the line from read_line
* Return: Splitting Line
*/

char **splitting_line(char *line)
{
	char *token, **array_returned;

	int counter = 0;

	array_returned = malloc(sizeof(char *) * 1024);

	token = strtok(line, " \n\t");

	while (token != NULL)
	{
		array_returned[counter] = token;
		token = strtok(NULL, " \n\t");
		counter++;
	}
	array_returned[counter] = NULL;

	return (array_returned);

}


