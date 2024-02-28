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

/**
 * str__ncmp - compares two strings.
 *
 * @s1: input const string
 * @s2: input const string
 * @n: input int
 *
 * Return: returns an integer
 */
int str__ncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
		{
			break;
		}
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * str__cpy - copy src to dest .
 *
 * @d: input char *
 * @s: input const char *
 *
 * Return: char *
 */
char *str__cpy(char *d, const char *s)
{
	int length;

	for (length = 0; s[length] != '\0'; ++length)
	{
		d[length] = s[length];
	}
	d[length] = '\0';
	return (d);
}

/**
 * str__cat - appends the src string to the dest string,
 *
 * @d: input string
 * @s: input const string
 *
 * Return: void
 */
char *str__cat(char *d, const char *s)
{
	char *result = d;

	while (*d != '\0')
	{
		d++;
	}

	while (*s != '\0')
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';

	return (result);
}
