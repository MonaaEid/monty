#ifndef MONTY_H_
#define MONTY_H_
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>


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


void free_stack(stack_t *head);
void m_push(stack_t **stack, unsigned int line_number, int value);
void m_pint(stack_t **stack, unsigned int line_number);
void mm_push(stack_t **stack, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pchar(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
void m_add(stack_t **stack, unsigned int line_number);
void m_nop(stack_t **stack, unsigned int line_number);
void m_sub(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void m_mul(stack_t **stack, unsigned int line_number);
void m_mod(stack_t **stack, unsigned int line_number);
/*void pchar_op(stack_t **stack, unsigned int line_number);*/
void pstr_op(stack_t **stack, unsigned int line_number);
void m_rotl(stack_t **stack, unsigned int line_number);
void m_rotr(stack_t **stack, unsigned int line_number);


ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void handle_oopcode(char *filenam);
/*void handle_oopcode(char *filename);*/
void handle_opcode(char *filename);

#endif
