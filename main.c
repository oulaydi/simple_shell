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
			exit(0);
		}
		tokenize = splitting_line(line);

		if (tokenize[0] == NULL)
		{
			free(tokenize);
			continue;
		}

		env_print(tokenize);

		exit_status(tokenize);

		execution(tokenize);
	}
	free(line);
	free(tokenize);
	return (0);
}
