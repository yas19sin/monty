#include "monty.h"

/**
 * get_opcodes - Get the array of opcodes and corresponding functions.
 *
 * Return: The array of opcodes and functions.
 */
instruction_t *get_opcodes(void)
{
	instruction_t *opcodes = malloc(sizeof(instruction_t) * 18);
	if (opcodes == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	opcodes[0].opcode = "push";
	opcodes[0].f = push;

	opcodes[1].opcode = "pall";
	opcodes[1].f = pall;

	opcodes[2].opcode = "pint";
	opcodes[2].f = pint;

	opcodes[3].opcode = "pop";
	opcodes[3].f = pop;

	opcodes[4].opcode = "swap";
	opcodes[4].f = swap;

	opcodes[5].opcode = "add";
	opcodes[5].f = add;

	opcodes[6].opcode = "nop";
	opcodes[6].f = nop;

	opcodes[7].opcode = "sub";
	opcodes[7].f = sub;

	opcodes[8].opcode = "div";
	opcodes[8].f = div_op;

	opcodes[9].opcode = "mul";
	opcodes[9].f = mul;

	opcodes[10].opcode = "mod";
	opcodes[10].f = mod;

	opcodes[11].opcode = "comments";
	opcodes[11].f = comments;

	opcodes[12].opcode = "pchar";
	opcodes[12].f = pchar;

	opcodes[13].opcode = "pstr";
	opcodes[13].f = pstr;

	opcodes[14].opcode = "rotl";
	opcodes[14].f = rotl;

	opcodes[15].opcode = "rotr";
	opcodes[15].f = rotr;

	opcodes[16].opcode = "stack";
	opcodes[16].f = stack;

	opcodes[17].opcode = "queue";
	opcodes[17].f = queue;

	return opcodes;
}


/**
 * execute_instruction - Executes the given instruction.
 * @line: The instruction line.
 * @stack: The stack.
 * @instructions: The array of opcodes and functions.
 * @line_number: The current line number.
 */
void execute_instruction(char *line, stack_t **stack, instruction_t *instructions, unsigned int line_number)
{
	char *opcode;
	int i = 0;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;

	while (i < 18)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	if (i == 18)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_opcodes - Frees the allocated memory for opcodes.
 * @instructions: The array of opcodes and functions.
 */
void free_opcodes(instruction_t *instructions)
{
	free(instructions);
}

/**
 * free_stack - Frees the stack.
 * @stack: The stack to be freed.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}

