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
  * rotl_opcode - rotate the stack to the top.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void rotl_opcode(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *curr, *new;

	if (isempty(*top) || !(*top)->next)
		return;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "ERROR: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = pop(top);
	new->prev = new->next = NULL;

	curr = *top;
	while (curr->next)
		curr = curr->next;

	curr->next = new;
	new->prev = curr;
}



/**
  * rotr_opcode - rotates the stack to the bottom.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void rotr_opcode(stack_t **top, __attribute__((unused)) unsigned int line)
{
	int temp;
	stack_t *curr;

	curr = *top;
	while (curr->next->next)
		curr = curr->next;

	temp = curr->next->n;

	free(curr->next);
	curr->next = NULL;

	push(top, temp);
}
