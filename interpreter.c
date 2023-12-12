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

	fp = fopen(filename, O_RDONLY);
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while (getline(&lineptr, &n, fp) != -1)
	{
		strarr = modify(lineptr);
		arg = atoi(strarr[1]);
		func = get_opcode(strarr[0]);
		if (func)
		{
			func(&top, lines);
		}
		lines++;
	}

	fclose(fp);
}

char **modify(char *str)
{
	char *strarr[];
	int args = 2;


	strarr[0] = strtok(str, " \0");
	strarr[1] = strtok(str, " \0");

	return (strarr);
	/*
	*int i, ch;
	*int spaces = 0;
	*i = ch = 0;
	*while (str[i])
	*{
	*	if (str[i] == ' ' && str[i + 1] == ' ')
	*		spaces = 1;
	*	i++;
	*}
	*/
}
