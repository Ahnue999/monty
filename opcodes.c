#include "monty.h"

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
		{"pop", pop_opcode}, {"pint", pint_opcode},
		{"swap", swap_opcode}, {"add", add_opcode},
		{"nop", nop_opcode}, {"sub", sub_opcode},
		{"mul", mul_opcode}, {"div", div_opcode},
		{"mod", mod_opcode}, {"pchar", pchar_opcode},
		{"pstr", pstr_opcode}, {"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
		{"stack", stack_opcode}, {"queue", queue_opcode},
		{NULL, NULL}
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
	int s = 0, n;

	if (aux.arg)
	{
		if (aux.arg[0] == '-')
			s = 1;
		for (; aux.arg[s]; s++)
		{
			if (aux.arg[s] < 48 || aux.arg[s] > 57)
			{
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line);
				fclose(aux.fp);
				free_stack(top);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
		fclose(aux.fp);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
	n = atoi(aux.arg);
	*top = push(top, n);
}


/**
 * pop_opcode - removes a member to a stack.
 * @top: a pointer to the top member of a stack.
 * @line: line number.
 *
 * Return: Void.
 */
void pop_opcode(stack_t **top, unsigned int line)
{
	if (isempty(*top))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	pop(top);
}


/**
 * pint_opcode - prints the value at the top of the function.
 * @top: a pointer to the top member of a stack.
 * @line: line number.
 *
 * Return: Void.
 */
void pint_opcode(stack_t **top, unsigned int line)
{
	if (isempty(*top))
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}


/**
 * pall_opcode - prints all members of a stack.
 * @top: a pointer to the top member of a stack.
 * @line: line number.
 *
 * Return: Void.
 */
void pall_opcode(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *temp;

	temp = *top;
	if (isempty(temp))
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
