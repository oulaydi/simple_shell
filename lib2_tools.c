#include "shell.h"

/**
* _isdigit - checks if a character is digit
* @c: The character to be checked
*
* Return: 1 if c is digit, 0 otherwise
*/

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}

	else
	{
		return (0);
	}
}

/**
* _putchar - writes the character c to stdout
* @c : The character to print.
*
* Return: On success 1.
*      On error -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}


/**
* print_number - Prints an integer
* @n: The integer to be printed
*/

void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');

		num = -n;
	}
	else
			num = n;
	if (num / 10)
		print_number(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * _atoi - converts string to int
 * @str: string to be converted
 * Return: int value
*/


int _atoi(const char *str)
{
	int result = 0;

	int sign = 1;

	int i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	else if (str[i] == '+')
	{
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}
