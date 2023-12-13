#include "monty.h"

/**
  * swap_opcode - swaps the top two elements of a stack.
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
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = temp;
}


/**
  * pchar_opcode - prints the char at the top of the stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void pchar_opcode(stack_t **top, unsigned int line)
{
	int ch;

	if (isempty(*top))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	ch = (*top)->n;

	if (ch < 0 || ch >= 128)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}



/**
  * nop_opcode - does nothing.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void nop_opcode(__attribute__((unused)) stack_t **top, unsigned int line)
{
	(void)line;
}
