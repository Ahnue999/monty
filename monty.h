#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct aux_s
{
	int arg;
	int mode;
} aux_t;

extern aux_t aux;

/* opcode funcs */
void (*get_opcode(char *))(stack_t **, unsigned int);
void push_opcode(stack_t **top, unsigned int line);
void pop_opcode(stack_t **top, unsigned int line);
void pint_opcode(stack_t **top, unsigned int line);
void pall_opcode(stack_t **top, unsigned int line);
void swap_opcode(stack_t **top, unsigned int line);
void add_opcode(stack_t **top, unsigned int line);
void sub_opcode(stack_t **top, unsigned int line);
void mul_opcode(stack_t **top, unsigned int line);
void div_opcode(stack_t **top, unsigned int line);
void mod_opcode(stack_t **top, unsigned int line);
void nop_opcode(stack_t **top, unsigned int line);
void pchar_opcode(stack_t **top, unsigned int line);
void pstr_opcode(stack_t **top, unsigned int line);
void rotl_opcode(stack_t **top, unsigned int line);
void rotr_opcode(stack_t **top, unsigned int line);
void stack_opcode(stack_t **top, unsigned int line);
void queue_opcode(stack_t **top, unsigned int line);

/* stack funcs */
int isempty(stack_t *top);
stack_t *push(stack_t **top, int data);
stack_t *push_queue(stack_t **top, int data);
int pop(stack_t **top);
void free_stack(stack_t **top);


void inter(FILE *fp, stack_t **top);
char **modify(char *);

#endif
