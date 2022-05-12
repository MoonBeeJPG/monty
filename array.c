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
void array(stack_t **stack, char *line, unsigned int number_line)
{
	int i;

	instruction_t array_f[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; array_f[i].opcode; i++)
	{
		if (strcmp(line, array_f[i].opcode) == 0)
		{
			array_f[i].f(stack, number_line);
			return;
		}
	}
	if (strlen(line) != 0 && line[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", number_line, line);
		exit (EXIT_FAILURE);
	}
}
