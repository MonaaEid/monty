#include "monty.h"

/*void opcode_function(stack_t **stack, unsigned int line_number)*/
/**/


void m_push(stack_t **stack, unsigned int line_number)
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
void m_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
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

void handle_opcode(char *filename)
{
	char opcode[100];
	FILE *file = fopen(filename, "r");
	instruction_t instructions[] = {
		{"push", m_push},
		{"pint", m_pint},
		{"pall", m_pall},
	};
	unsigned int i;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (file == NULL) {
		fprintf(stderr, "Error: Cannot open file %s\n", filename);
		exit(EXIT_FAILURE);
	}


	while (fgets(opcode, sizeof(opcode), file) != NULL) {
		opcode[strcspn(opcode, "\n")] = '\0';

		for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}

		if (i == sizeof(instructions) / sizeof(instructions[0]))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}

	fclose(file);
}
