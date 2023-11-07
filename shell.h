#ifndef _MAI_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define TOK_BUFFER_SIZE 128
#define TOKEN_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **ptr_environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @ptr_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **ptr_environ;
	char *pid;
} all_data_shell;

/**
 * struct sepa_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sepa_list_s
{
	char separator;
	struct sepa_list_s *next;
} sepa_list;

/**
 * struct stored_list - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct stored_list
{
	char *line;
	struct stored_list *next;
} line_list;

/**
 * struct var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct var_list
{
	int len_var;
	char *val;
	int len_val;
	struct var_list *next;
} var_store;

/**
 * struct intrinsic_s - intrinsic struct for command args.
 * @name: The name of the command intrinsic i.e cd, quit, env
 * @f: data type pointer function.
 */
typedef struct intrinsic_s
{
	char *name;
	int (*f)(all_data_shell *datash);
} intrinsic_t;

/* lists.c */
sepa_list *append_sepa_node_end(sepa_list **head, char sep);
void free_sepa_list(sepa_list **head);
line_list *append_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* lists2.c */
var_store *append_var_node(var_store **head, int lvar, char *var, int lval);
void free_var_list(var_store **head);

/* str functions */
char *_str_cat(char *dest, const char *src);
char *_str_cpy(char *dest, char *src);
int _str_cmp(char *s1, char *s2);
char *_str_chr(char *s, char c);
int _str_spn(char *s, char *accept);

/* memory.c */
void _memo_cpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **rlcdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* str2.c */
char *_str_dup(const char *s);
int _str_len(const char *s);
int _cmp_char(char str[], const char *delim);
char *_str_tok(char str[], const char *delim);
int _is_a_digit(const char *s);

/* str3.c */
void rev_str(char *s);

/* verify_syntax_err.c */
int iterative_char(char *input, int i);
int err_sepa_op(char *input, int i, char last);
int fst_char(char *input, int *i);
void display_syntax_err(all_data_shell *datash, char *input, int i, int bool);
int verify_syntax_err(all_data_shell *datash, char *input);

/* shell_fori.c */
char *without_cmd(char *in);
void shell_fori(all_data_shell *datash);

/* read line */
char *r_line(int *i_eof);

/* divide_line.c */
char *swap_a_char(char *input, int bool);
void append_nodes(sepa_list **head_s, line_list **head_l, char *input);
void go_to_next(sepa_list **list_s, line_list **list_l, all_data_shell *datash);
int divide_cmds(all_data_shell *datash, char *input);
char **divide_line(char *input);

/* print_var.c */
void verify_env(var_store **h, char *in, all_data_shell *data);
int verify_vars(var_store **h, char *in, char *st, all_data_shell *data);
char *rep_input_a_var(var_store **head, char *input, char *new_input, int nlen);
char *rep_str_to_var(char *input, all_data_shell *datash);

/* recuperate_line.c */
void recuperate_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t recuperate_line_2(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int exe_line(all_data_shell *datash);

/* cmd_exec.c */
int is_cur_dir(char *path, int *i);
char *_pwd(char *cmd, char **ptr_environ);
int is_exe(all_data_shell *datash);
int verify_err_cmd(char *dir, all_data_shell *datash);
int cmd_exe(all_data_shell *datash);

/* env_var1.c */
char *_getenv_var(const char *name, char **ptr_environ);
int display_env(all_data_shell *datash);

/* env_var2.c */
char *copy_info_to_create(char *name, char *value);
void set_env_var(char *name, char *value, all_data_shell *datash);
int compares_env_var(all_data_shell *datash);
int delete_env_var(all_data_shell *datash);

/* change_dir.c */
void cd_no9ta(all_data_shell *datash);
void cd_path(all_data_shell *datash);
void cd_joj_no9at(all_data_shell *datash);
void cd_oulaydi(all_data_shell *datash);

/* chaneg_cur_dir.c */
int chaneg_cur_dir(all_data_shell *datash);

/* get_intrinsic */
int (*get_intrinsic(char *cmd))(all_data_shell *datash);

/* _quit.c */
int quit_shell(all_data_shell *datash);

/* stdlib.c */
int len_of_num(int n);
char *_itoa(int n);
int _atoi(char *s);

/* err1.c */
char *CatErrMsg(all_data_shell *, char *, char *, char *);
char *err_get_cd(all_data_shell *datash);
char *err_not_404(all_data_shell *datash);
char *err_quit_shell(all_data_shell *datash);

/* err2.c */
char *err_get_as(char **args);
char *err_env(all_data_shell *datash);
char *err_syntax(char **args);
char *err_chmod(char **args);
char *err_path_chmod(all_data_shell *datash);

/* get_err.c */
int recuperate_err(all_data_shell *datash, int eval);

/* recuperate_sigint.c */
void recuperate_sigint(int sig_h);

/* help.c */
void help_env(void);
void help_set_env(void);
void help_unsetenv(void);
void help_general(void);
void help_quit(void);

/* help2.c */
void help(void);
void help_as(void);
void help_cd(void);

/* recuperate_help.c */
int recuperate_help(all_data_shell *datash);

#endif
