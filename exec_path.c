#include "shell.h"


/**
 * exec_path - return the command with achux
 *
*/


char *exec_path(char *command)
{
	char *find_path_return = find_path("PATH");
	char *token;
	char *buff;

	token = strtok(find_path_return, ":");

	while (token != NULL)
	{
		buff = malloc(_strlen(token) + 1 + _strlen(command) + 1);
		_strcpy(buff, token);
		token = strtok(NULL, ":");
		_strcat(buff, "/");
		_strcat(buff, command);

		if (access(buff, R_OK) == 0)
		{
			free(find_path_return);
			return (buff);
		}

		free(buff);
	}

	free(find_path_return);
	return (command);
}
