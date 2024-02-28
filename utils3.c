#include "main.h"

/**
 * bltIN__cd - cd Env
 * @dt: the structure "data" parameter
 * Return: void
 */
void bltIN__cd(data_struct *dt)
{
	char *directory = dt->tokens_arr[1];
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
	}
	set__env(dt, "PWD", cwd);
	if (!directory)
	{
		directory = get__env("HOME");
	}
	if (chdir(directory) == (0 - 1))
	{
		perror("cd");
	}
	else
	{
		set__env(dt, "OLDPWD", get__env("PWD"));
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd() error");
		}
		set__env(dt, "PWD", cwd);
	}
}

