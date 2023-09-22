#include "monty.h"
/**
 * free_stack - a function that frees a doubly linked list
 * @head: head of the list
 */
void free_stack(stack_t *head)
{
	stack_t *top;

	top = head;
	while (head)
	{
		top = head->next;
		free(head);
		head = top;
	}
}
