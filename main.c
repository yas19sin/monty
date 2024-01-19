#include "monty.h"

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

	return (EXIT_SUCCESS);
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

/**
 * init_opcodes - Initializes an array of opcodes with corresponding functions.
 *
 * Return: A pointer to the array of opcodes and functions.
 */
instruction_t *init_opcodes(void)
{
	instruction_t *opcodes = malloc(sizeof(instruction_t) * 18);

	if (opcodes == NULL)
		exit(EXIT_FAILURE);

	opcodes[0].opcode = "push";
	opcodes[0].f = push;
	opcodes[1].opcode = "pall";
	opcodes[1].f = pall;
	opcodes[2].opcode = "pint";
	opcodes[2].f = pint;
	opcodes[3].opcode = "pop";
	opcodes[3].f = pop;
	opcodes[4].opcode = "nop";
	opcodes[4].f = nop;
	opcodes[5].opcode = "swap";
	opcodes[5].f = swap;
	opcodes[6].opcode = "add";
	opcodes[6].f = add;
	opcodes[7].opcode = "sub";
	opcodes[7].f = sub;
	opcodes[8].opcode = "div";
	opcodes[8].f = div_op;
	opcodes[9].opcode = "mul";
	opcodes[9].f = mul;
	opcodes[10].opcode = "mod";
	opcodes[10].f = mod;
	opcodes[11].opcode = "pchar";
	opcodes[11].f = pchar;
	opcodes[12].opcode = "pstr";
	opcodes[12].f = pstr;
	opcodes[13].opcode = "rotl";
	opcodes[13].f = rotl;
	opcodes[14].opcode = "rotr";
	opcodes[14].f = rotr;
	opcodes[15].opcode = "queue";
	opcodes[15].f = queue;
	opcodes[16].opcode = "stack";
	opcodes[16].f = stack;
	return (opcodes);
}

/**
 * get_opcodes - Gets the array of opcodes and corresponding functions.
 *
 * Return: The array of opcodes and functions.
 */
instruction_t *get_opcodes(void)
{
	return (init_opcodes());
}


