#include "monty.h"

/*void opcode_function(stack_t **stack, unsigned int line_number)*/


void m_push(stack_t **stack, unsigned int line_number) {
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
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
    /*printf("%d pushed to stack\n", line_number);*/
}
void m_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
void handle_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    instruction_t instructions[] = {
    {"push", m_push},
    {"pint", m_pint},
    };
    unsigned int i;
    for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
    }

    printf("Unknown opcode: %s\n", opcode);
}
