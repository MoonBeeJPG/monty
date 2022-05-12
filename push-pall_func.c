#include "monty.h"
/**
* push - Function that pushed a new node to the end of the stack
*
* @stack: Doubly linked list representation of the stack (or queue)
* @line_number: Number of lines passed
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *num;

	num = strtok(NULL, DELIM);
	if (num == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = atoi(num);
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
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	
	(void) line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
