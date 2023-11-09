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
	int r_v;

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
		if (_strcmp(tokenize[0], "env") == 0)
		{
			env_print();
			free(tokenize);
			continue;
		}
		if (_strcmp(tokenize[0], "exit") == 0)
		{
			r_v = exit_status(tokenize);
			free(tokenize);
			free(line);
			exit(r_v);
		}
		execution(tokenize);
	}
	if (line != NULL)
		free(line);
	if (tokenize != NULL)
	{
		free(tokenize);
	}
	return (0);
}
