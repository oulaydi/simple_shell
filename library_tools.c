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
        return NULL;
    }

    _strcpy(new_str, src);
    return (new_str);
}
