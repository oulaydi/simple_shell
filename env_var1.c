#include "main.h"

/**
 * compares_env_names - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int compares_env_names(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv_var - get an environment variable
 * @name: name of the environment variable
 * @ptr_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv_var(const char *name, char **ptr_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; ptr_environ[i]; i++)
	{
		/* If name and env are equal */
		mov = compares_env_names(ptr_environ[i], name);
		if (mov)
		{
			ptr_env = ptr_environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * display_env - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int display_env(all_data_shell *datash)
{
	int i, j;

	for (i = 0; datash->ptr_environ[i]; i++)
	{

		for (j = 0; datash->ptr_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->ptr_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
