#include "main.h"

/**
 * cd_no9ta - changes to the parent directory
 *
 * @datash: data relevant (environ)
 *
 * Return: no return
 */
void cd_no9ta(all_data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	get_cwd(pwd, sizeof(pwd));
	cp_pwd = _str_dup(pwd);
	set_env_var("OLDPWD", cp_pwd, datash);
	dir = datash->args[1];
	if (_str_cmp(".", dir) == 0)
	{
		set_env_var("PWD", cp_pwd, datash);
		free(cp_pwd);
		return;
	}
	if (_str_cmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_str(cp_strtok_pwd);
	cp_strtok_pwd = _str_tok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _str_tok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_str(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env_var("PWD", cp_strtok_pwd, datash);
	}
	else
	{
		chdir("/");
		set_env_var("PWD", "/", datash);
	}
	datash->status = 0;
	free(cp_pwd);
}

/**
 * cd_path - changes to a directory given
 * by the user
 *
 * @datash: data relevant (directories)
 * Return: no return
 */
void cd_path(all_data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	get_cwd(pwd, sizeof(pwd));

	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
		recuperate_err(datash, 2);
		return;
	}

	cp_pwd = _str_dup(pwd);
	set_env_var("OLDPWD", cp_pwd, datash);

	cp_dir = _str_dup(dir);
	set_env_var("PWD", cp_dir, datash);

	free(cp_pwd);
	free(cp_dir);

	datash->status = 0;

	chdir(dir);
}

/**
 * cd_joj_no9at - changes to the previous directory
 *
 * @datash: data relevant (environ)
 * Return: no return
 */
void cd_joj_no9at(all_data_shell *datash)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	get_cwd(pwd, sizeof(pwd));
	cp_pwd = _str_dup(pwd);

	p_oldpwd = _getenv_var("OLDPWD", datash->ptr_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _str_dup(p_oldpwd);

	set_env_var("OLDPWD", cp_pwd, datash);

	if (chdir(cp_oldpwd) == -1)
		set_env_var("PWD", cp_pwd, datash);
	else
		set_env_var("PWD", cp_oldpwd, datash);

	p_pwd = _getenv_var("PWD", datash->ptr_environ);

	write(STDOUT_FILENO, p_pwd, _str_len(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	datash->status = 0;

	chdir(p_pwd);
}

/**
 * cd_oulaydi - changes to home directory
 *
 * @datash: data relevant (environ)
 * Return: no return
 */
void cd_oulaydi(all_data_shell *datash)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	get_cwd(pwd, sizeof(pwd));
	p_pwd = _str_dup(pwd);

	home = _getenv_var("HOME", datash->ptr_environ);

	if (home == NULL)
	{
		set_env_var("OLDPWD", p_pwd, datash);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		recuperate_err(datash, 2);
		free(p_pwd);
		return;
	}

	set_env_var("OLDPWD", p_pwd, datash);
	set_env_var("PWD", home, datash);
	free(p_pwd);
	datash->status = 0;
}
