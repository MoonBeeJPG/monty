#include "monty.h"
stack_t **global_head;
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
	stack_t *head;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	head = NULL;
	global_head = &head;

	readit(argv[1], &head);

	atexit(frees);

	exit(EXIT_SUCCESS);
}
