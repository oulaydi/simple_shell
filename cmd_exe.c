#include "main.h"

/**
 * is_cur_dir - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cur_dir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _pwd - locates a command
 *
 * @cmd: command name
 * @ptr_environ: environment variable
 * Return: location of the command.
 */
char *_pwd(char *cmd, char **ptr_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenv_var("PATH", ptr_environ);
	if (path)
	{
		ptr_path = _str_dup(path);
		len_cmd = _str_len(cmd);
		token_path = _str_tok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cur_dir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _str_len(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_str_cpy(dir, token_path);
			_str_cat(dir, "/");
			_str_cat(dir, cmd);
			_str_cat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _str_tok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_exe - determines if is an executable
 *
 * @datash: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_exe(all_data_shell *datash)
{
	struct stat st;
	int i;
	char *input;

	input = datash->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	recuperate_err(datash, 127);
	return (-1);
}

/**
 * verify_err_cmd - verifies if user has permissions to access
 *
 * @dir: destination directory
 * @datash: data structure
 * Return: 1 if there is an error, 0 if not
 */
int verify_err_cmd(char *dir, all_data_shell *datash)
{
	if (dir == NULL)
	{
		recuperate_err(datash, 127);
		return (1);
	}

	if (_str_cmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			recuperate_err(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			recuperate_err(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exe - executes command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cmd_exe(all_data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_exe(datash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _pwd(datash->args[0], datash->ptr_environ);
		if (verify_err_cmd(dir, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _pwd(datash->args[0], datash->ptr_environ);
		else
			dir = datash->args[0];
		execve(dir + exec, datash->args, datash->ptr_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}
