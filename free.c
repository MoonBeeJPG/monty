#include "monty.h"
/**
* frees - Function that frees memory previusly allocated
*/
void frees(void)
{
	stack_t *freebie, *current = NULL;

	freebie = *head;

	while (freebie)
	{
		current = freebie->next;
		free(freebie);
		freebie = current;
	}
}
