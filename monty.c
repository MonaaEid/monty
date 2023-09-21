#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	/*ssize_t nread;*/
	unsigned int line_number = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
       /* fprintf(stderr, "L%s: usage: push integer\n", argv[2]);*/

		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can’t open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*nread = getdelim(&line, &len, 36, file);*/
	while (read_line > 0)
	{
		read_line = getline(&line, &len, file);
		line_number++;
		if (read_line > 0)
		{
		/*_execute(line, &stack, line_number, file);*/
			handle_opcode(line, &stack, line_number);
	    /*execute(line, &stack, line_number);*/
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}
