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
void array(stack_t **stack, char *op, unsigned int line_num)
{
	int i;
	instruction_t ops[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_num);
			return;
		}

	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_num, op);
		exit(EXIT_FAILURE);
	}
}
