#include "shell.h"

void exit_status(char **arr)
{
	if (_strcmp(arr[0], "exit") == 0)
	{
		if (arr[1] != NULL)
		{
			int int_value;
			int_value = atoi(arr[1]);

			if (int_value >= 0)
				exit(int_value);

			else if (int_value < 0)
			{
				exit_neg_err(int_value);
				exit(2);
			}

		}

		exit(0);
	}
}

void exit_neg_err(int num)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	print_number(num);
	_putchar('\n');
}
