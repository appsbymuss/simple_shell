#ifndef SIMPLE_HEADER
#define SIMPLE_HEADER

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define PROMPT "#csisfun$ "

extern char **environ;

/**
 * struct data - has principal data
 * @tokens_arr: Array of tokens to pass for execve
 * @cmd_input: The user input, the command line
 * @shell_n: The name of the shell program
 * @exit_status_last: last exit status of last command executed
 * @flag_set_env: 1 if user did exec setenv (use it to free memory)
 */
typedef struct data
{
	char **tokens_arr;
	char *cmd_input;
	const char *shell_n;
	int exit_status_last;
	int flag_set_env;
} data_struct;

/**
 * struct builtin - principal data holder
 * @cmd: blttn cmd
 * @f: func
 */
typedef struct builtin
{
	const char *cmd;
	void (*f)(data_struct *dt);
} builtin;

int bltIN_execute(data_struct *dt);
/* bltIN_execute */
void bltIN_quit(data_struct *dt);
/* bltIN_quit */
void bltIN_get_env(data_struct *dt);
/* bltIN_get_env */
void bltIN__setenv(data_struct *dt);
/* bltIN__setenv */
void bltIN__unsetenv(data_struct *dt);
/* bltIN__unsetenv */
void bltIN__cd(data_struct *dt);
/* bltIN__cd */


void _printf(const char *stri);
void free_array(char **arr);
void split(data_struct *dt, const char *del);
void initialize_datastruct(data_struct *dt, const char *shell_n);
/* initialize_datastruct */
void r__cmd(data_struct *dt);
/* r__cmd */

void p__error(const char *s1, const char *s2);
/* p__error */
void _trim(char *s);
void *re_alloc(void *pointer, unsigned int n_size);
/* re_alloc */

void start__process(data_struct *dt);
/* start__process */
void hand__sigint(int sig);
/* hand__sigint */
void _exec(data_struct *dt);

char *get__env(char *name);
/* get__env */
int _which(data_struct *dt);
int set__env(data_struct *dt, char *name, char *value);
/* set__env */

