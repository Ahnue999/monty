#include "monty.h"

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




/**
  * mod_opcode - modulates the top two elements of a stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void mod_opcode(stack_t **top, unsigned int line)
{
	int temp;

	if (isempty(*top) || !(*top)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = pop(top);
	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*top)->n %= temp;
}
