#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

extern int arg;

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

/* opcode funcs */
void (*get_opcode(char *))(stack_t **, unsigned int);
void push_opcode(stack_t **top, unsigned int line);
void pop_opcode(stack_t **top, unsigned int line);
void pint_opcode(stack_t **top, unsigned int line);
void pall_opcode(stack_t **top, unsigned int line);

/* string funcs */
int _strcmp(char *, char *);

/* stack funcs */
int isempty(stack_t *top);
stack_t *push(stack_t **top, int data);
stack_t *pop(stack_t **top);


void inter(char *);
char **modify(char *);

#endif
