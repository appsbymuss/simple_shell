#include "main.h"

/**
 * main - main
 * @argc: argv size
 * @argv: array of argv
 * Return: success is 0
 */

int main(int argc, char **argv)
{
	data_struct dt;
	(void)argc;
	initialize_datastruct(&dt, argv[0]);
	_exec(&dt);

	return (0);
}
