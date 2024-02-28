#include "main.h"

/**
 * str__len - return the nbr of char in str
 * @str: string input
 * Return: nbr of char in str.
 */

unsigned int str__len(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}


/**
 * str__cmp - compares two strings.
 *
 * @s1: input const string
 * @s2: input const string
 *
 * Return: returns an integer
 */
int str__cmp(const char *s1, const char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

