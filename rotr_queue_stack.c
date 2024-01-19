#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		last = *stack;

		while (last->next)
			last = last->next;

		last->next = temp;
		temp->prev = last;
		*stack = temp->next;
		temp->next = NULL;
		(*stack)->prev = NULL;
	}
}

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty byte code file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty byte code file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * enqueue - Adds a new node at the end of the queue.
 * @stack: A pointer to the top of the stack.
 * @value: Value to be added to the queue.
 */
void enqueue(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		stack_t *temp = *stack;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}
}
