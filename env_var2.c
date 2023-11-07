#include "main.h"

/**
 * copy_info_to_create - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info_to_create(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _str_len(name);
	len_value = _str_len(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_str_cpy(new, name);
	_str_cat(new, "=");
	_str_cat(new, value);
	_str_cat(new, "\0");

	return (new);
}

/**
 * set_env_var - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_env_var(char *name, char *value, all_data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datash->ptr_environ[i]; i++)
	{
		var_env = _str_dup(datash->ptr_environ[i]);
		name_env = _str_tok(var_env, "=");
		if (_str_cmp(name_env, name) == 0)
		{
			free(datash->ptr_environ[i]);
			datash->ptr_environ[i] = copy_info_to_create(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->ptr_environ = rlcdp(datash->ptr_environ, i, sizeof(char *) * (i + 2));
	datash->ptr_environ[i] = copy_info_to_create(name, value);
	datash->ptr_environ[i + 1] = NULL;
}

/**
 * compares_env_var - compares env variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int compares_env_var(all_data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		recuperate_err(datash, -1);
		return (1);
	}

	set_env_var(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * delete_env_var - deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int delete_env_var(all_data_shell *datash)
{
	char **reallocptr_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		recuperate_err(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->ptr_environ[i]; i++)
	{
		var_env = _str_dup(datash->ptr_environ[i]);
		name_env = _str_tok(var_env, "=");
		if (_str_cmp(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		recuperate_err(datash, -1);
		return (1);
	}
	reallocptr_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->ptr_environ[i]; i++)
	{
		if (i != k)
		{
			reallocptr_environ[j] = datash->ptr_environ[i];
			j++;
		}
	}
	reallocptr_environ[j] = NULL;
	free(datash->ptr_environ[k]);
	free(datash->ptr_environ);
	datash->ptr_environ = reallocptr_environ;
	return (1);
}
