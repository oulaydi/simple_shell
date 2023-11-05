#include "shell.h"

/**
* main - khaliha 3ala lah
* Return: Always (0) Success
*/

int main(void)
{
	char *line = NULL;
	int ronaldo = 0;
	char **tokenize;
	size_t size = 0;


	while (1)
	{
		if (isatty(0))
			write(STDOUT_FILENO, ">> ", 3);

		ronaldo = getline(&line, &size, stdin);

		if (ronaldo == -1 || line == NULL)
		{
			free(line);
			perror("READ_LINE :");
			exit(EXIT_FAILURE);
		}
		tokenize = splitting_line(line);

		if (tokenize[0] == NULL)
		{
			continue;
		}

		if (strcmp(tokenize[0], "exit") == 0)
		{
			free(tokenize);
			break;
		}

		execution(tokenize);

		free_lmlawi(tokenize);
	}

	free(line);
	return (0);
}
