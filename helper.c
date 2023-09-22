#include "monty.h"
/**
 * handle_opcode - handle the opcade
 * @filename: the file
*/
void handle_opcode(char *filename)
{
	char opcode[100];
	FILE *file = fopen(filename, "r");
	instruction_t instructions[] = {
		/*{"push", m_push},*/
		{"pint", m_pint},
		{"pall", m_pall},
	};
	unsigned int i;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(opcode, sizeof(opcode), file) != NULL)
	{
		opcode[strcspn(opcode, "\n")] = '\0';

		for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
		{
			if (strncmp(opcode, "push ", 5) == 0)
			{
				m_push(&stack, line_number);
			}
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
