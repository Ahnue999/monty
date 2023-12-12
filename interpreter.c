#include "main.h"

/**
 * inter - reads a monty file and interprete it.
 * @filename: the name of the file.
 *
 * Return: void.
 */
void inter(char *filename)
{
	FILE *fp = NULL;
	char *lineptr = NULL;
	size_t n;

	fp = fopen(filename, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);

	while (getline(&lineptr, &n, fd) != -1)
	{

	}

	fclose(fp);
}
