#include "shell.h"

char *find_path(char *path)
{
	int i = 0;
	char *env_buff, *token, *switchh;

	while (environ[i] != NULL)
	{
		env_buff = _strdup(environ[i]);
		token = strtok(env_buff, "=");

		if (_strcmp(token, path) == 0)
		{
			switchh = _strdup(strtok(NULL, "\n"));
			free(env_buff);
			return (switchh);
		}

		free(env_buff);
		i++;
	}

	return NULL;

}
