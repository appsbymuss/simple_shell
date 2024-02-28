#include "main.h"

/**
 * get__env - retrieves the value of an environment variable.
 * @name: string input
 * Return: value of an environment variable
 */

char *get__env(char *name)
{
	int i = -1;
	size_t name_len;

	if (name == NULL || *name == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	name_len = str__len(name);

	while (environ[++i])
	{
		if (!str__ncmp(environ[i], name, name_len) && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}
	return (NULL);
}

/**
 * _which - locate the executable file associated with a given command.
 * @d: string input
 * Return: void
 */
int _which(data_struct *dt)
{
	char *token, *path,
		*paths = malloc(str__len(get__env("PATH") ? get__env("PATH") : "") + 1);
	size_t token_len;
	int find = -1;

	if (!get__env("PATH"))
		goto exit_l;
	str__cpy(paths, get__env("PATH"));
	if (paths == NULL)
		goto exit_l;
	token = strtok(paths, ":");
	while (token)
	{
		token_len = str__len(token) + str__len(dt->tokens_arr[0]) + 2;
		path = malloc(token_len);
		if (path == NULL)
			return (find);
		str__cpy(path, token);
		str__cat(path, "/");
		str__cat(path, dt->tokens_arr[0]);
		if (access(path, F_OK) == 0)
		{
			free(dt->tokens_arr[0]);
			dt->tokens_arr[0] = str__dup(path);
			free(path);
			find = 0;
			break;
		}
		free(path);
		token = strtok(NULL, ":");
	}
exit_l:
	free(paths);
	return (find);
}

/**
 * create_new_entry - Initialize a new environment variable,
 *  or modify an existing one
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char *create_new_entry(char *name, char *value)
{
	size_t new_len = strlen(name) + strlen(value) + 2;
	char *new_entry = malloc(new_len);

	if (new_entry == NULL)
		return (NULL);

	strcpy(new_entry, name);
	strcat(new_entry, "=");
	strcat(new_entry, value);

	return (new_entry);
}
/**
 * _new_environ - Initialize a new environment variable,
 *  or modify an existing one
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char **_new_environ(char *name, char *value)
{
	int env_len = 0, i = 0;
	char *new_entry;
	char **new_environ;

	while (environ[env_len])
		env_len++;
	new_entry = create_new_entry(name, value);
	if (new_entry == NULL)
		return (NULL);
	new_environ = get__env(name) ? malloc((env_len + 1) * sizeof(char *))
								: malloc((env_len + 2) * sizeof(char *));

	if (!new_environ)
	{
		free(new_entry);
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		new_environ[i] = malloc(strlen(environ[i]) + 1);
		if (!new_environ[i])
		{
			free_array(new_environ);
			free(new_entry);
			return (NULL);
		}
		if (strncmp(environ[i], name, strlen(name)) == 0
		&& environ[i][strlen(name)] == '=')
			strcpy(new_environ[i], new_entry);
		else
			strcpy(new_environ[i], environ[i]);
	}
	if (!get__env(name))
	{
		new_environ[env_len] = new_entry;
		new_environ[env_len + 1] = NULL;
	}
	else
		new_environ[env_len] = NULL;
	return (new_environ);
}

/**
 * set__env - Initialize a new environment variable, or modify an existing one
 * @d: to use the flag
 * @name: variable name
 * @value: variable value
 * Return: void
 */
int set__env(data_struct *dt, char *name, char *value)
{
	char **new_environ;

	if (!name || !value)
		return (-1);

	new_environ = _new_environ(name, value);
	if (!new_environ)
		return (-1);
	environ = new_environ;
	dt->flag_set_env = 1;

	return (0);
}
