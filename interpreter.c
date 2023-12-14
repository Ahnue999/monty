#include "monty.h"

/**
 * inter - reads a monty file and interprete it.
 * @fp: a pointer to the file.
 * @top: a pointer to the top of the stack.
 *
 * Return: void.
 */
void inter(FILE *fp, stack_t **top)
{
	char *lineptr = NULL;
	size_t n;
	int lines = 1;
	char **strarr;
	void (*func)(stack_t **, unsigned int);

	while (getline(&lineptr, &n, fp) != -1)
	{
		lineptr[strcspn(lineptr, "\n")] = 0;
		strarr = modify(lineptr);
		if (!strarr || !strarr[0])
			continue;
		if (strarr[1])
		{
			aux.arg = atoi(strarr[1]);
			if (!aux.arg)
			{
				if (strcmp(strarr[1], "0") != 0)
					aux.arg = -104;
			}
		}
		func = get_opcode(strarr[0]);
		if (func)
			func(top, lines);
		else
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lines, strarr[0]);
			free(strarr), fclose(fp);
			exit(EXIT_FAILURE);
		}
		lines++, free(strarr);
	}
	free(lineptr);
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

	str[strcspn(str, "\n")] = 0;
	strarr = malloc(sizeof(char *) * args);
	if (!strarr || strcmp(str, "") == 0)
		return (NULL);

	strarr[0] = strtok(str, " \t\n");
	if (strarr[0][0] == '#')
		return (NULL);
	strarr[1] = strtok(NULL, " \t\n");

	return (strarr);
}
