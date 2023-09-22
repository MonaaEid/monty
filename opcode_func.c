#include "monty.h"

/*void opcode_function(stack_t **stack, unsigned int line_number)*/
/**
 * m_push - prints the stack
 * @stack: stack head
 * @line_number: no used
 * Return: no return
*/

void m_push(stack_t **stack, unsigned int line_number, int value)
{
	if(!isdigit(value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (isdigit(value))
	{
		stack_t *node = malloc(sizeof(stack_t));

		if (node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		node->n = value;
		node->prev = NULL;
		node->next = *stack;
		if (*stack != NULL)
		{
			(*stack)->prev = node;
		}
		*stack = node;
	}

}
/**
 * mm_push - prints the stack
 * @stack: stack head
 * @line_number: no used
 * Return: no return
*/

void mm_push(stack_t **stack, unsigned int line_number)
{
        if (isdigit(line_number))
        {
                stack_t *node = malloc(sizeof(stack_t));

                if (node == NULL)
                {
                        fprintf(stderr, "Error: malloc failed\n");
                        exit(EXIT_FAILURE);
                }
                node->n = line_number;
                node->prev = NULL;
                node->next = *stack;
                if (*stack != NULL)
                {
                        (*stack)->prev = node;
                }
                *stack = node;
                printf("%d\n", line_number);
                free(node);
        }
        else
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }
}
/**
 * m_pall - prints the stack
 * @stack: stack head
 * @line_number: no used
*/
void m_pall(stack_t **stack, unsigned int line_number)
{
        stack_t *h;
        (void)line_number;

        h = *stack;
        if (h == NULL)
                return;
        while (h)
        {
                printf("%d\n", h->n);
                h = h->next;
        }
}
/**
 * m_pint - prints the stack
 * @stack: stack head
 * @line_number: no used
*/
void m_pint(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                exit(EXIT_FAILURE);
        }
} 
