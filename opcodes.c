#include "main.h"

/**
 * get_opcode - gets an opcode function.
 * @opcode: the name of the function to get.
 *
 * Return: a pointer to the function.
 */
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t insts[] = {
		{"push", push_opcode}, {"pall", pall_opcode},
		{"pop", pop_opcode}, {NULL, NULL}
	};

	i = 0;
	while (insts[i].opcode)
	{
		if (strcmp(insts[i].opcode, opcode) == 0)
			return (insts[i].f);
		i++;
	}
	return (NULL);
}

/**
 * push_opcode - adds a member to a stack.
 * @top: a pointer to the top member of a stack.
 * @line: line number.
 *
 * Return: Void.
 */
void push_opcode(stack_t **top, unsigned int line)
{
	if (!arg)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer", line);
		exit(EXIT_FAILURE);
	}
	*top = push(top, arg);
}


/**
 * pop - removes a member to a stack.
 * @top: a pointer to the top member of a stack.
 * @line: line number.
 *
 * Return: Void.
 */
void pop_opcode(stack_t **top, unsigned int line)
{
	if (isempty(*top))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack", line);
		exit(EXIT_FAILURE);
	}
	*top = pop(top);
}


/**
 * pall_opcode - prints all members of a stack.
 * @top: a pointer to the top member of a stack.
 * @line: line number.
 *
 * Return: Void.
 */
void pall_opcode(stack_t **top, unsigned int line)
{
	stack_t *temp;

	temp = *top;
	if (!isempty(temp))
	{
		dprint(STDERR_FILENO, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}