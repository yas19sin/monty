#include "monty.h"

int queue_mode = 0;

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execute_monty(argv[1]);

	return EXIT_SUCCESS;
}

/**
 * execute_monty - Executes the Monty byte code from the specified file.
 * @file_path: Path to the Monty byte code file.
 */
void execute_monty(char *file_path)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t *instructions = NULL;

	file = fopen(file_path, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	instructions = get_opcodes();
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		execute_instruction(line, &stack, instructions, line_number);
	}

	free_opcodes(instructions);
	free_stack(&stack);
	free(line);
	fclose(file);
}