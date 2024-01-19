#include "monty.h"

/**
 * push - Adds a new node at the beginning of a stack_t list.
 * @stack: Double pointer to the head of the stack.
 * @line_number: line_number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n\t\r");
	int value;
	stack_t *new_node;

	if (!value_str || !isdigit(value_str[0]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	print_stack(*stack);
}

/**
 * print_stack - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 */
void print_stack(stack_t *stack)
{
	stack_t *temp = stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
