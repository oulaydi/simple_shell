#include "shell.h"

/**
 * exit_status - Handle the exit built in
 * @arr: full cmd
 * Return: int value
*/

int exit_status(char **arr)
{
	if (_strcmp(arr[0], "exit") == 0)
	{
		if (arr[1] != NULL)
		{
			int int_value;

			int_value = _atoi(arr[1]);

			if (int_value >= 0)
			{
				return (int_value);
			}

			else if (int_value < 0)
			{
				exit_neg_err(int_value);
				return (2);
			}

		}

	}

	return (0);
}

/**
 * exit_neg_err - print to stderr the err message
 * @num: return of exit_status
 * Return: Void
*/

void exit_neg_err(int num)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	print_number(num);
	_putchar('\n');
}
