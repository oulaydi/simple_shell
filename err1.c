#include "main.h"

/**
 * CatErrMsg - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *CatErrMsg(all_data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_str_cpy(error, datash->av[0]);
	_str_cat(error, ": ");
	_str_cat(error, ver_str);
	_str_cat(error, ": ");
	_str_cat(error, datash->args[0]);
	_str_cat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_str_cat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_str_cat(error, datash->args[1]);
	}

	_str_cat(error, "\n");
	_str_cat(error, "\0");
	return (error);
}

/**
 * err_get_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *err_get_cd(all_data_shell *datash)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = _itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _str_len(datash->args[1]);
	}

	length = _str_len(datash->av[0]) + _str_len(datash->args[0]);
	length += _str_len(ver_str) + _str_len(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = CatErrMsg(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * err_not_404 - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *err_not_404(all_data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _itoa(datash->counter);
	length = _str_len(datash->av[0]) + _str_len(ver_str);
	length += _str_len(datash->args[0]) + 16;
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
	_str_cat(error, ": not found\n");
	_str_cat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * err_quit_shell - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *err_quit_shell(all_data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _itoa(datash->counter);
	length = _str_len(datash->av[0]) + _str_len(ver_str);
	length += _str_len(datash->args[0]) + _str_len(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_str_cpy(error, datash->av[0]);
	_str_cat(error, ": ");
	_str_cat(error, ver_str);
	_str_cat(error, ": ");
	_str_cat(error, datash->args[0]);
	_str_cat(error, ": Illegal number: ");
	_str_cat(error, datash->args[1]);
	_str_cat(error, "\n\0");
	free(ver_str);

	return (error);
}
