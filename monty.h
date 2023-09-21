#ifndef MONTY_H
#define MONTY_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
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

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;

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

extern bus_t bus;

void free_stack(stack_t *head);
void m_pint(stack_t **stack, unsigned int line_number);
void m_push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

void handle_opcode(char *opcode, stack_t **stack, unsigned int line_number);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int _execute(char *content, stack_t **stack, unsigned int counter, FILE *file);

#endif
