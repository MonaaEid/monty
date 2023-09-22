#include "monty.h"
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: arguments v
* Return: Always 0 (Success)
*/
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
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can’t open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		read_line = getline(&line, &len, file);
		line_number++;
		if (read_line > 0)
		{
		/*_execute(line, &stack, line_number, file);*/
		/*	handle_opcode(line, &stack, line_number);*/
			handle_opcode(argv[1]);
	    /*execute(line, &stack, line_number);*/
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}
