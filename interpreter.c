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
	int lines = 0;
	stack_t *top = NULL;
	char **strarr;
	void (*func)(stack_t **, unsigned int);

	fp = fopen(filename, O_RDONLY);
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&lineptr, &n, fp) != -1)
	{
		strarr = modify(lineptr);
		arg = atoi(strarr[1]);
		func = get_opcode(strarr[0]);
		if (func)
			func(&top, lines);
		lines++;
		free(strarr);
	}

	fclose(fp);
}

/**
 * modify - removes the spaces from the input string and
 * divides it into tokens.
 * @str: the string to modify.
 *
 * Return: an array of tokens.
 */
char **modify(char *str)
{
	char **strarr;
	int args = 2;

	strarr = malloc(sizeof(char *) * args);

	strarr[0] = strtok(str, " \0");
	strarr[1] = strtok(NULL, " \0");

	return (strarr);
}
