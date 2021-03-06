#include "monty.h"
/**
* mul - This function adds the top two nodes of the stack, stores it in
* the second node, and pops off the top node
* @stack: The stack list
* @line_number: The line number of the file
* Return: The edited stack
*/
stack_t *mul(stack_t **stack, unsigned int line_number)
{
    int sum = 0;
    stack_t *head = *stack;

    /* Check if stack is NULL */
    if (head == NULL || head->next == NULL)
    {
        /* Print error, free, and exit */
        fprintf(stderr, "L%d: can't add, stack too short\n",
line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    /* Sum first two nodes, and store it in second node */
    sum = (head->n) * (head->next->n);
    head->next->n = sum;
    pop(stack, 0);

    return (*stack);
}
/**
* mod - This function adds the top two nodes of the stack, stores it in
* the second node, and pops off the top node
* @stack: The stack list
* @line_number: The line number of the file
* Return: The edited stack
*/
stack_t *mod(stack_t **stack, unsigned int line_number)
{
    int sum = 0;
    stack_t *head = *stack;

    /* Check if stack is NULL */
    if (head == NULL || head->next == NULL)
    {
        /* Print error, free, and exit */
        fprintf(stderr, "L%d: can't add, stack too short\n",
line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    /* Sum first two nodes, and store it in second node */
    sum = (head->n) % (head->next->n);
    head->next->n = sum;
    pop(stack, 0);

    return (*stack);
}
/**
* div - This function adds the top two nodes of the stack, stores it in
* the second node, and pops off the top node
* @stack: The stack list
* @line_number: The line number of the file
* Return: The edited stack
*/
stack_t *divi(stack_t **stack, unsigned int line_number)
{
    int sum = 0;
    stack_t *head = *stack;

    /* Check if stack is NULL */
    if (head == NULL || head->next == NULL)
    {
        /* Print error, free, and exit */
        fprintf(stderr, "L%d: can't add, stack too short\n",
line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    /* Sum first two nodes, and store it in second node */
    sum = (head->n) / (head->next->n);
    head->next->n = sum;
    pop(stack, 0);

    return (*stack);
}
stack_t *rotl(stack_t **stack,
	      unsigned int line_number __attribute__ ((unused)))
{
	stack_t *head = *stack;

	while (!head)
		head = head->next;

	/* stack now points to the second node */
	*stack = (*stack)->next;
	head->next = (*stack)->prev;
	(*stack)->prev = NULL;
	head->next->prev = head;
	head = head->next;
	head->next = NULL;

	return (*stack);
}

/**
* pchar - prints the char at the top of the stack
* @stack: The stack list
* @line_num: The line number of the file
* Return: The head of the stack
*/
stack_t *pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr,
			"L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	putchar(head->n);
	putchar('\n');

	return (*stack);
}
