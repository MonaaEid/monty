#include "monty.h"
/**
 * m_div -  removes the top element of the stack.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	m_pop(stack, line_number);
}
/**
 * m_mul -  removes the top element of the stack.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	m_pop(stack, line_number);
}
/**
 * m_mod -  removes the top element of the stack.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	m_pop(stack, line_number);
}
/**
 * m_pchar -  removes the top element of the stack
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr_op -  removes the top element of the stack.
 * @stack: pointer to stack head
 * @line_number: line executing in monty
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
