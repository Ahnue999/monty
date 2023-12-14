#include "monty.h"

aux_t aux;
/**
 * main - entry point.
 * @argc: arguments count.
 * @argv: arguments vector.
 *
 * Return: 1 when succeed and 0 otherwise.
 */
int main(int argc, char **argv)
{
	char *filename;
	FILE *fp = NULL;
	stack_t *top = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];

	if (access(filename, R_OK) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fp = fopen(filename, "r");
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	aux.mode = 'S';
	inter(fp, &top);
	fclose(fp);
	free_stack(&top);
	return (0);
}

/**
 * free_stack - frees a stack.
 * @top: the stack to free.
 *
 * Return: void.
 */
void free_stack(stack_t **top)
{
	stack_t *temp;

	while (*top)
	{
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}
