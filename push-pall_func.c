#include "monty.h"
/**
* push - Function that pushed a new node to the end of the stack
*
* @stack: Doubly linked list representation of the stack (or queue)
* @line_number: Number of lines passed
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *addition;

	addition = strtok(NULL, DELIMS);

	if (!addition)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = atoi(addition);
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = node;
	
	*stack = node;
}
/**
* pall - Functiont that print all the value from the stack
*
* @stack: Doubly linked list representation of the stack (or queue)
* @line_number: Number of lines passed
*/
void pall(stack_ **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
