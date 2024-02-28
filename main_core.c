#include "main.h"

/**
 * start__process - new process
 * @dt: data struct input
 * Return: void
 */

void start__process(data_struct *dt)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(dt->tokens_arr[0], dt->tokens_arr, NULL) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	if (WIFEXITED(status))
		dt->exit_status_last = WEXITSTATUS(status);
	return;
free:
	perror(dt->shell_n);
	free_array(dt->tokens_arr);
	free(dt->cmd_input);
	exit(EXIT_FAILURE);
}

/**
 * hand__sigint - handle signint
 * @sig: signal
 * Return: void
 */

void hand__sigint(int sig)
{
	(void)sig;
	exit(EXIT_FAILURE);
}

/**
 * _exec - execute a command
 * @dt: data
 * Return: void
 */

void _exec(data_struct *dt)
{
	const char prompt[] = PROMPT;

	signal(SIGINT, hand__sigint);

	while (1 == 1)
	{
		if (isatty(STDIN_FILENO))
			_printf(prompt);

		r__cmd(dt);
		if (str__len(dt->cmd_input) != 0)
		{
			split(dt, " ");
			if (!bltIN_execute(dt))
			{
				_which(dt);
				if (access(dt->tokens_arr[0], F_OK) == -1)
				{
					perror(dt->shell_n);
				}
				else
				{
					start__process(dt);
				}
			}
			free_array(dt->tokens_arr);
		}
		free(dt->cmd_input);
	}
}

