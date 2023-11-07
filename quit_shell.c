#include "main.h"

/**
 * quit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int quit_shell(all_data_shell *datash)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		is_digit = _is_a_digit(datash->args[1]);
		str_len = _str_len(datash->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			recuperate_err(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (ustatus % 256);
	}
	return (0);
}