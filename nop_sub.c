#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty byte code file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
