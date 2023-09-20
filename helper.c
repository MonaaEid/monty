#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*void opcode_function(stack_t **stack, unsigned int line_number)*/

void push(stack_t **stack, unsigned int line_number) {
    if (isdigit(line_number))
    {
        stack_t *node = malloc(sizeof(stack_t));
        if (node == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        node->n = line_number;
        node->prev = NULL;
        node->next = *stack;
        if (*stack != NULL)
            (*stack)->prev = node;
        *stack = node;
        printf("%d\n", line_number);
    }
    else
    fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
    /*printf("%d pushed to stack\n", line_number);*/
}
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

