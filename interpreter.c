#include "monty.h"

/**
 * inter - reads a monty file and interprete it.
 * @filename: the name of the file.
 * @top: a pointer to the top of the stack.
 *
 * Return: void.
 */
void inter(char *filename, stack_t **top)
{
	FILE *fp = NULL;
	char *lineptr = NULL;
	size_t n;
	int lines = 1;
	char **strarr;
	void (*func)(stack_t **, unsigned int);

	fp = fopen(filename, "r");
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&lineptr, &n, fp) != -1)
	{
		lineptr[strcspn(lineptr, "\n")] = 0;
		strarr = modify(lineptr);
		if (strarr[1])
			arg = atoi(strarr[1]);
		func = get_opcode(strarr[0]);
		if (func)
		{
			func(top, lines);
		}
		else
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lines, strarr[0]);
			exit(EXIT_FAILURE);
		}
		lines++;
		free(strarr);
	}

	free(lineptr);
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

	strarr[0] = strtok(str, " \0\n");
	strarr[1] = strtok(NULL, " \0\n");

	return (strarr);
}
