#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp && temp->n != 0 && (temp->n >= 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;

		last = *stack;

		while (last->next)
			last = last->next;

		last->next = temp;
		temp->prev = last;
		temp->next = NULL;
	}
}