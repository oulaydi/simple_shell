#include "main.h"

/**
 * exe_line - finds intrinsics and commands
 *
 * @datash: data relevant (args)
 * Return: 1 on success.
 */
int exe_line(all_data_shell *datash)
{
	int (*intrinsic)(all_data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	intrinsic = get_intrinsic(datash->args[0]);

	if (intrinsic != NULL)
		return (intrinsic(datash));

	return (cmd_exe(datash));
}
