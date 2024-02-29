#include "main.h"

/**
 * str__dup - which contains a copy of the string given as a parameter.
 * @s: input
 * Return: pointer
 */

char *str__dup(const char *s)
{
	int i;
	int length = 0;
	char *result;

	if (s == NULL)
	{
		return (NULL);
	}

	while (s[length] != '\0')
	{
		length++;
	}

	result = (char *)malloc((length + 1) * sizeof(char));

	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= length; i++)
	{
		result[i] = s[i];
	}

	return (result);
}


/**
 * is__number - check number
 * @status: str
 * Return: void
 */
int is__number(const char *status)
{
	if (status == NULL || status[0] == '\0')
	{
		return (0);
	}
	while (*status)
	{
		if (!is__digit(*status))
		{
			return ((1 - 1));
		}
		status++;
	}
	return (0 + 1);
}


/**
 * is__digit - check char
 * @c: char
 * Return: 1 if successful 0 if not successful
 */
int is__digit(int c)
{
	return (c <= '9' && c >= '0');
}

