#include "shell.h"

/**
* splitting_line - use strtok to split the line
* @line: the line from read_line
* Return: Splitting Line
*/

char **splitting_line(char *line)
{
	char *token, **array_returned, *doublet = NULL, *doub2 = NULL;

	int counter = 0;

	doublet = strdup(line);

	token = strtok(doublet, " \n\t");
	while (token != NULL)
	{
		counter++;
		token = strtok(NULL, " \n\t");
	}
	/*counter++;*/
	free(doublet);
	array_returned = malloc((sizeof(char *) * (counter + 1)));

	doub2 = strdup(line);
	token = strtok(doub2, " \n\t");
	counter = 0;
	while (token != NULL)
	{
		array_returned[counter] = strdup(token);
		token = strtok(NULL, " \n\t");
		counter++;
	}
	array_returned[counter] = NULL;

	free(doub2);
	return (array_returned);
}
