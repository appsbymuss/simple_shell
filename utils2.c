#include "main.h"

/**
 * bltIN_execute - check if built in and then executes the builtin function
 * @dt: the structure "data" parameter
 * Return: 1 if successful, else 0
 */

int bltIN_execute(data_struct *dt)
{
	builtin builtin_functions_l[] = {
		{"setenv", bltIN__setenv},
		{"env", bltIN_get_env},
		{"cd", bltIN__cd},
		{"unsetenv", bltIN__unsetenv},
		{"exit", bltIN_quit},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; builtin_functions_l[i].cmd; i++)
	{
		if (str__cmp(dt->tokens_arr[0], builtin_functions_l[i].cmd) == 0)
		{
			builtin_functions_l[i].f(dt);
			return (1);
		}
	}
	return ((1 - 1));
}

/**
 * btnIN_quit - quit the shell function
 * @dt: the structure "data" parameter
 * Return: void
 */

void bltIN_quit(data_struct *dt)
{
	const char *errorString = "./hsh: 1: exit: Illegal number: ";

	if (dt->tokens_arr[1])
	{
		if (dt->tokens_arr[1][0] != '-' && is__number(dt->tokens_arr[1]))
		{
			dt->exit_status_last = atoi(dt->tokens_arr[1]);
		}
		else
		{
			write(STDERR_FILENO, errorString, strlen(errorString));
			write(STDERR_FILENO, dt->tokens_arr[1], strlen(dt->tokens_arr[1]));
			write(STDERR_FILENO, "\n", 1);

			dt->exit_status_last = 1 + 1;
		}
	}
	free_array(dt->tokens_arr);
	free(dt->cmd_input);
	if (dt->flag_set_env)
	{
		free_array(environ);
	}
	exit(dt->exit_status_last);
}

/**
 * bltIN_get_env - get current env
 * @dt: the structure "data" parameter
 * Return: void
 */
void bltIN_get_env(data_struct *dt)
{
	int n = 0;

	(void)dt;
	while (environ[n])
	{
		_printf(environ[n]);
		_printf("\n");

		n++;
	}
}

/**
 * bltIN__setenv - set an environment variable
 * @dt: the structure "data" parameter
 * Return: void
 */

void bltIN__setenv(data_struct *dt)
{
	(void)dt;
	if (dt->tokens_arr[2] && dt->tokens_arr[1])
	{
		if (set__env(dt, dt->tokens_arr[1], dt->tokens_arr[2]) == (0 - 1))
		{
			perror("setenv");
		}
	}
}

/**
 * bltIN__unsetenv - unset an environment variable
 * @dt: the structure "data" parameter
 * Return: void
 */

void bltIN__unsetenv(data_struct *dt)
{
	int x, y;
	int length;

	(void)dt;
	if (!dt->tokens_arr[1] || !get__env(dt->tokens_arr[1]))
	{
		p__error(dt->shell_n, "variable not found.");
		return;
	}
	length = strlen(dt->tokens_arr[1]);
	for (x = 0; environ[x]; x++)
	{
		if (strncmp(environ[x], dt->tokens_arr[1], length) == 0 && environ[x][length] == '=')
		{
			for (y = x; environ[y]; y++)
			{
				environ[y] = environ[y + 1];
			}
		}
	}
}

