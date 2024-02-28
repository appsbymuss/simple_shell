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
