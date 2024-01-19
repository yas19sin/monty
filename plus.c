#include "monty.h"


/**
 * execute_instruction - Executes the given instruction.
 * @line: The instruction line.
 * @stack: The stack.
 * @instructions: The array of opcodes and functions.
 * @line_number: The current line number.
 */
void execute_instruction(char *line, stack_t **stack,
	instruction_t *instructions, unsigned int line_number)
{
	char *opcode;
	int i = 0;
	char *line_copy = strdup(line);

	opcode = strtok(line_copy, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
	{
		free(line_copy);
		return;
	}

	while (i < 18)
	{
		if (strcmp(opcode, "queue") == 0)
		{
			enqueue(stack, line_number);
		}
		else if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			free(line_copy);
			return;
		}
		i++;
	}

	if (i == 18)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	free(line_copy);
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
