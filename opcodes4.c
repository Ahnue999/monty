#include "monty.h"


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
  * pstr_opcode - prints the string starting at the top of the stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void pstr_opcode(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *temp;


	temp = *top;
	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}



/**
  * stack_opcode - change the orientaion to a stack.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void stack_opcode(__attribute__((unused)) stack_t **top, unsigned int line)
{
	mode = 'S';
	(void)line;
}


/**
  * queue_opcode - change the orientaion to a queue.
  * @top: a pointer to the top of the stack.
  * @line: line number.
  *
  * Return: void.
  */
void queue_opcode(__attribute__((unused))stack_t **top, unsigned int line)
{
	mode = 'Q';
	(void)line;
}
