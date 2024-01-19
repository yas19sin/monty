#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *new_node;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = sum;
	new_node->prev = NULL;

	new_node->next = (*stack)->next->next;
	if ((*stack)->next->next)
	{
		(*stack)->next->next->prev = new_node;
	}

	free(*stack);
	free((*stack)->next);

	*stack = new_node;
}