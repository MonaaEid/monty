#include "monty.h"
/**
 * m_rotl -  removes the top element of the stack.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second_top = (*stack)->next;
	(void)line_number;

	if (top && second_top)
	{
		*stack = second_top;
		while (second_top->next)
		{
			second_top = second_top->next;
		}
		second_top->next = top;
		top->next = NULL;
	}
}
/**
 * m_rotr -  removes the top element of the stack.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *prev = NULL;
	(void)line_number;


	if (current && current->next)
	{
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack;
		*stack = current;
	}
}
