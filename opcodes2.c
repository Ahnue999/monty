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
  * add_opcode - adds the top two elements of a stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void add_opcode(stack_t **top, unsigned int line)
{
	int temp;

	if (isempty(*top) || !(*top)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = pop(top);
	(*top)->n += temp;
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




/**
  * sub_opcode - subs the top two elements of a stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void sub_opcode(stack_t **top, unsigned int line)
{
	int temp;

	if (isempty(*top) || !(*top)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = pop(top);
	(*top)->n -= temp;
}



/**
  * div_opcode - divides the top two elements of a stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void div_opcode(stack_t **top, unsigned int line)
{
	int temp;

	if (isempty(*top) || !(*top)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = pop(top);
	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*top)->n /= temp;
}



/**
  * mul_opcode - multiplies the top two elements of a stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void mul_opcode(stack_t **top, unsigned int line)
{
	int temp;

	if (isempty(*top) || !(*top)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = pop(top);
	(*top)->n *= temp;
}
