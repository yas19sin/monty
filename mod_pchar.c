#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 * of the stack by the top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - Prints the char at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty byte code file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * comments - Doesn't do anything.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void comments(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}