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
	stack_t *top = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	aux.mode = 'S';
	inter(argv[1], &top);
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
