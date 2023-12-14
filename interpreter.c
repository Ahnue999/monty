#include "monty.h"

/**
 * inter - reads a monty file and interprete it.
 * @fp: a pointer to the file.
 * @top: a pointer to the top of the stack.
 *
 * Return: void.
 */
void inter(stack_t **top)
{
	char *lineptr = NULL;
	size_t n;
	int lines = 1;
	char *code;
	void (*func)(stack_t **, unsigned int);

	while (getline(&lineptr, &n, aux.fp) != -1)
	{
		lineptr[strcspn(lineptr, "\n")] = 0;
		code = modify(lineptr);
		if (!code)
			continue;
		func = get_opcode(code);
		if (func)
			func(top, lines);
		else
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lines, code);
			fclose(aux.fp);
			exit(EXIT_FAILURE);
		}
		lines++;
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
char *modify(char *str)
{
	char *code;

	str[strcspn(str, "\n")] = 0;
	if (strcmp(str, "") == 0)
		return (NULL);

	code = strtok(str, " \t\n");
	if (code && code[0] == '#')
		return (NULL);
	aux.arg = strtok(NULL, " \t\n");

	return (code);
}
