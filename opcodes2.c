#include "monty.h"

/**
  * swap_opcode - swaps the top to elements of a stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void swap_opcode(stack_t **top, unsigned int line)
{
	int temp;

	if (isempty(*top) || !(*top)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short", line);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = temp;
}
