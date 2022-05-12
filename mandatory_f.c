#include "monty.h"
/**
* pint - Function that prints the value at the top of the stack,
* followed by a new line
*
* @stack: Doubly linked list representation of the stack (or queue)
* @line_number: Number of lines passed
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
* pop - Function that removes the top element of the stack
*
* @stack: Doubly linked list representation of the stack (or queue)
* @line_number: Number of lines passed
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack || !(*stack))
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->next;
	free(current);
}
/**
* swap - Function that swaps the top two element of the stack
*
* @stack: Doubly linked list representation of the stack (or queue)
* @line_number: Number of lines passed
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: cant't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = (*stack)->next;

	(*stack)->prev = current;
	(*stack)->next = current->next;

	current->prev = NULL;

	if (current->next)
		current->next->prev = *stack;
	current->next = *stack;

	*stack = current;
}
/**
* add - Function that adds the top two element of the stack
*
* @stack: Doubly linked list representation of the stack (or queue)
* @line_number: Number of lines passed
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int addition;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	addition = current->n + current->next->n;
	current->next->n = addition;

	*stack = current->next;

	free(current);
}
/**
* nop - Function that doesn't do anything
*
* @stack: Doubly linked list representation of the stack (or queue)
* @line_number: Number of lines passed
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
