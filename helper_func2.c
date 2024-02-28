#include "main.h"

/**
 * p__error - echo to stderr
 * @s1: str1
 * @s2: str2
 * Return: void
 */

void p__error(const char *s1, const char *s2)
{
	if (!s2 || !s1)
	{
		return;
	}

	while (*s1)
	{
		write(STDERR_FILENO, s1, 1);
		s1++;
	}

	write(STDERR_FILENO, ": ", 2);

	while (*s2)
	{
		write(STDERR_FILENO, s2, 1);
		s2++;
	}

	write(STDERR_FILENO, "\n", 1);
}


/**
 * _trim - take off leading/trailing spaces
 * @s: str
 * Return: void.
 */

void _trim(char *s)
{
	int x, y, length = str__len(s);

	for (x = 0; (s[x] == '\t' || s[x] == ' ') && x < length; x++)
		;

	for (y = 0; x < length ; x++, y++)
	{
		s[y] = s[x];
	}

	s[y] = (char)0;

	for (x = str__len(s) - 1; (s[x] == '\t' || s[x] == ' ') && x > 0; x--)
	{
		s[x] = (char)0;
	}
}


/**
 * re_alloc - it is used to reallocate a memory
 * @pointer: pointer void
 * @n_size: unsigned int
 * Return: the newly allocated memory
 */
void *re_alloc(void *pointer, unsigned int n_size)
{
	char *ptr;
	unsigned int i, tep = n_size, old_size = sizeof(pointer);

	if (old_size == n_size)
	{
		return (pointer);
	}
	if (pointer == NULL)
	{
		return (malloc(n_size));
	}

	if (n_size > old_size)
	{
		tep = old_size;
	}

	if (n_size == 0)
	{
		free(pointer);
		return (NULL);
	}

	ptr = malloc(n_size);

	for (i = 0; i < tep; i++)
	{
		ptr[i] = ((char *)pointer)[i];
	}
	free(pointer);

	return (ptr);
}

