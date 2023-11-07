#include "main.h"

/**
 * err_env - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *err_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = _itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _str_len(datash->av[0]) + _str_len(ver_str);
	length += _str_len(datash->args[0]) + _str_len(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_str_cpy(error, datash->av[0]);
	_str_cat(error, ": ");
	_str_cat(error, ver_str);
	_str_cat(error, ": ");
	_str_cat(error, datash->args[0]);
	_str_cat(error, msg);
	_str_cat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * err_path_chmod - error message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *err_path_chmod(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = _itoa(datash->counter);
	length = _str_len(datash->av[0]) + _str_len(ver_str);
	length += _str_len(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_str_cpy(error, datash->av[0]);
	_str_cat(error, ": ");
	_str_cat(error, ver_str);
	_str_cat(error, ": ");
	_str_cat(error, datash->args[0]);
	_str_cat(error, ": Permission denied\n");
	_str_cat(error, "\0");
	free(ver_str);
	return (error);
}
