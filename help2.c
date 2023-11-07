#include "main.h"

/**
 * help - Help information for the intrinsic help.
 * Return: no return
 */
void help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _str_len(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _str_len(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _str_len(help));
}
/**
 * help_as - Help information for the intrinsic alias.
 * Return: no return
 */
void help_as(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _str_len(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _str_len(help));
}
/**
 * help_cd - Help information for the intrinsic alias.
 * Return: no return
 */
void help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _str_len(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _str_len(help));
}
