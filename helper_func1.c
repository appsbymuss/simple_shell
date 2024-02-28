#include "main.h"

/**
 * _printf - printf function
 * @stri: string
 * Return: void
 */

void _printf(const char *stri)
{
	if (!stri)
	{
		return;
	}
	while (*stri)
	{
		write(STDOUT_FILENO, stri, 1);
		stri++;
	}
}

/**
 * free_array - frees array
 * @arr: the array argument
 * Return: void
 */

void free_array(char **arr)
{
	int n;

	if (!arr)
	{
		return;
	}

	for (n = 0; arr[n]; n++)
	{
		free(arr[n]);
		arr[n] = NULL;
	}

	free(arr);
}

/**
 * split - splits a string using a delimiter
 * @dt: data parameter
 * @del: delimiter string
 * Return: void
 */

void split(data_struct *dt, const char *del)
{
	char *token_str;
	int ntoken = 0;

	dt->tokens_arr = malloc(2 * sizeof(char *));
	if (dt->tokens_arr == NULL)
	{
		free(dt->cmd_input);
		perror(dt->shell_n);
		exit(EXIT_FAILURE);
	}
	dt->tokens_arr[0] = NULL;
	dt->tokens_arr[1] = NULL;

	token_str = strtok(dt->cmd_input, del);
	while (token_str)
	{
		dt->tokens_arr = realloc(dt->tokens_arr, (ntoken + 2) * sizeof(char *));
		if (dt->tokens_arr == NULL)
		{
			goto free_a;
		}
		dt->tokens_arr[ntoken] = str__dup(token_str);
		if (dt->tokens_arr[ntoken] == NULL)
		{
			goto free_a;
		}
		ntoken++;
		token_str = strtok(NULL, del);
	}
	dt->tokens_arr[ntoken] = NULL;
	return;
free_a:
	free_array(dt->tokens_arr);
	free(dt->cmd_input);
	perror(dt->shell_n);
	exit(EXIT_FAILURE);
}

/**
 * initialize_datastruct - initialize data
 * @dt: data struct input
 * @shell_n: str input
 * Return: void
 */

void initialize_datastruct(data_struct *dt, const char *shell_n)
{
	dt->cmd_input = NULL;
	dt->flag_set_env = 0;
	dt->tokens_arr = NULL;
	dt->exit_status_last = EXIT_SUCCESS;
	dt->shell_n = shell_n;
}

/**
 * r__cmd - read the command from the prompt
 * @dt: data struct input
 * Return: void
 */

void r__cmd(data_struct *dt)
{
	size_t num = 0;
	ssize_t nu_read;
	int i = 0;

	nu_read = get__line(&dt->cmd_input, &num, stdin);

	if (nu_read == -1)
	{
		free(dt->cmd_input);
		exit(EXIT_SUCCESS);
	}

	dt->cmd_input[nu_read - 1] = '\0';
	_trim(dt->cmd_input);

	for (i = 0; dt->cmd_input[i] != '\0'; i++)
	{
		if ((dt->cmd_input[i] == (char)35 && dt->cmd_input[i - 1] == (char)32) || dt->cmd_input[0] == (char)35)
		{
			dt->cmd_input[i] = (char)0;
			break;
		}
	}

	_trim(dt->cmd_input);
}

