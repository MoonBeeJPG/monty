#include "monty.h"
/*
* readit - Function that reads the input
*
* @stack: Doubly linked list representation of the stack (or queue)
*/
void readit(char *input, stack_t **stack)
{
	size_t lenght;
	ssize_t reading;
	unsigned int number = 0;
	char *command, *line = NULL;
	FILE *foc;

	foc = fopen(input, "r");

	if (!foc)
	{
		printf("Error: can't open file %s\n", input);
		exit(EXIT_FAILURE);
	}

	reading = getline(&line, &lenght, foc);

	while (reading != -1)
	{
		command = strtok(line, DELIM);
		number++;

		if (command)
			array(stack, command, number);
	}

	if (line)
		free(line);

	fclose(foc);
}
