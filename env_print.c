#include "shell.h"

/**
 * env_print - print the env
*/

/**
 * env_print - prints the environment variables
 */
void env_print(void)
{
    char **env = environ;
		while (*env != NULL)
		{
			char *curr_env = *env;
			int len = 0;
			while (curr_env[len] != '\0')
			{
				len++;
			}
			write(STDOUT_FILENO, curr_env, len);
			write(STDOUT_FILENO, "\n", 1);
			env++;

		}
}
