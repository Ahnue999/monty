#include "main.h"

/**
 * main - entry point.
 * @argc: arguments count.
 * @argv: arguments vector.
 *
 * Return: 1 when succeed and 0 otherwise.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	inter(argv[1]);
	return (0);
}