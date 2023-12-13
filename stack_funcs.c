#include "main.h"

/**
 * isempty - checks whether a stack is empty.
 * @top: a pointer to the top of the stack.
 *
 * Return: 1 if empty and 0 if not.
 */
int isempty(stack_t *top)
{
	if (!top)
		return (0);
	return (1);
}

/**
 *
 */
stack_t *push(stack_t **top, int data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = data;
	new->prev = new->next = NULL;

	if (isempty(*top))
	{
		*top = new;
		return (new);
	}
	
	(*top)->prev = new;
	new->next = *top;
	*top = new;

	return (new);
}

/**
 *
 */
stack_t *pop(stack_t **top)
{
	if (!(*top))
		return NULL;

	*top = (*top)->next;
	free((*top)->prev);

	return (*top);
}