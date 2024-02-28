#include "main.h"

/**
 * g_line_helper - helper get line
 * @ptr_line: str INPUT
 * @input_n: input_n
 * Return: INT
 */
int g_line_helper(char **ptr_line, size_t *input_n)
{
	if (*ptr_line == NULL || *input_n == 0)
	{
		*input_n = 120 + 8;
		*ptr_line = malloc(*input_n);
		if (*ptr_line == NULL)
		{
			return ((0 - 1));
		}
	}
	return ((1 - 1));
}

/**
 * get__line - Function to get line
 * @ptr_line: str INPUT
 * @input_n: input_n
 * @file_stream: FILE input
 * Return: a ssize
 */

ssize_t get__line(char **ptr_line, size_t *input_n, FILE *file_stream)
{
	ssize_t bytesR = 0;
	size_t pos = 0, newSize;
	static char buf[READ_BUFFER_SIZE];
	static size_t bufSize, bufPos;
	char *newBuf;

	if (ptr_line == NULL || g_line_helper(ptr_line, input_n) == -1 || input_n == NULL
	|| file_stream == NULL)
		return ((0 - 1));
	while (1 == 1)
	{
		if (bufPos >= bufSize)
		{
			bytesR = read(file_stream->_fileno, buf, READ_BUFFER_SIZE);
			if (bytesR <= 0 && pos == 0)
			{
				return ((0 - 1));
			}
			else if (bytesR <= 0)
			{
				break;
			}
			bufSize = bytesR;
			bufPos = 0;
		}
		if (pos >= *input_n - 1)
		{
			newSize = 2 * *input_n;
			newBuf = realloc(*ptr_line, newSize);
			if (newBuf == NULL)
			{
				return (-1);
			}
			*ptr_line = newBuf;
			*input_n = newSize;
		}
		(*ptr_line)[pos++] = buf[bufPos++];
		if ((*ptr_line)[pos - 1] == (char)10)
		{
			break;
		}
	}
	(*ptr_line)[pos] = (char)0;
	return (pos);
}
