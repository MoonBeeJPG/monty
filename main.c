#include "monty.h"
stack_t **head;
/**
* main - Main function
*
* @argc: Quantity of arguments passed to the program
* @argv: Arguments vector
*
* Return: On success, EXIT_SUCCESS, on failure, EXIT_FAILURE
*/
int main(int argc, char *argv[])
{
	stack_t *header;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	header = NULL;
	head = &header;

	readit(argv[1], &header);

	atexit(frees);

	return (EXIT_SUCCESS);
}
