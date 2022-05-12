#include "monty.h"
/**
* array - Function that compares the reading line and matches it
* with the corresponding function if its have
*
* @stack: Double linked list represetnation of a stack (or queue)
* @line: Input line
* @number_line: Number of lines passed
*
*/
void get_op(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t valid_ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; valid_ops[i].opcode != NULL; i++)
	{
		if (strcmp(valid_ops[i].opcode, op) == 0)
		{
			valid_ops[i].f(stack, line_number);
			return;
		}
	}

	dprintf(STDOUT_FILENO,
		"L%u: unknown instruction %s\n",
		line_number, op);
	exit(EXIT_FAILURE);
}
