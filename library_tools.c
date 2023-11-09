#include "shell.h"

/**
* _strcat - Concatenate Two Arrays
* @dest: The destination string
* @src: The source string
* Return: The destination string
*/

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, z;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
		j++;

	for (z = 0; z < j; z++)
	{
		dest[i + z] = src[z];
	}

	dest[i + j] = '\0';

	return (dest);
}

/**
* *_strcpy - copies the string pointed to by ste
* @dest: char type string
* @src: char type string
* Description: Copy the string pointed to by pointer sre to
* the buffer pointed to by 'dest'
* Return: Pointer to 'dest'
*/

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');
	return (dest);
}

/**
* _strlen - Calculate the lenght of a string.
* @s: Pointer that point to a string
* Return: Lenght of Str
*/

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{

	}
	return (i);
}

/**
* _strcmp - function that compares two strings
* @s1: first string
* @s2: second string
* Return: Always 0 (Success)
*/

int _strcmp(char *s1, char *s2)
{
	for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
	}
	return (0);
}

/**
* _strdup - function that duplicates a string
* @src: first string
* Return: new_str
*/

char *_strdup(char *src)
{
	size_t len = _strlen(src) + 1;
	char *new_str =malloc(len * sizeof(char));

	if (new_str == NULL)
	{
		return (NULL);
	}

	_strcpy(new_str, src);
	return (new_str);
}

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


int custom_atoi(const char *str)
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
