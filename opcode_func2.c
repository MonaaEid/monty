#include "monty.h"
/**
 * m_pop -  removes the top element of the stack.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
/**
 * m_swap - swaps two top num of stack
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * m_add - adds top two num of stack
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	m_pop(stack, line_number);
}

/**
 * m_nop - doesn’t do anything.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * m_sub - doesn’t do anything.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	m_pop(stack, line_number);
}
