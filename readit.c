#include "monty.h"
/**
* readit - Function that reads the input
*
* @input: Input line
* @stack: Doubly linked list representation of the stack (or queue)
*/
void readit(char *input, stack_t **stack)
{
	size_t len;
	ssize_t read_line;
	unsigned int num = 0;
	char *line = NULL;
	FILE *fd;
	char *command;

	fd = fopen(input, "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", input);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		command = strtok(line, DELIM);
		num++;

		if (command)
			array(stack, command, num);
	}

	if (line)
		free(line);

	fclose(fd);
}
