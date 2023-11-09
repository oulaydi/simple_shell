#include "shell.h"

/**
 * cmd_error_handle - print to the stderr msg err
 * @cmd: command fail
 * Return: Void
*/

void cmd_error_handle(char *cmd)
{
	char *error_msg = "./hsh: 1: ";
	char *not_found_msg = ": not found\n";

	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, not_found_msg, _strlen(not_found_msg));
}
