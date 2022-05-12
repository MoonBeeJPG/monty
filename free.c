#include "monty.h"
/**
* frees - Function that frees memory previusly allocated
*/
void frees(void)
{
	stack_t *to_free;
	stack_t *temp = NULL;

	to_free = *global_head;

	while (to_free)
	{
		temp = to_free->next;

		free(to_free);

		to_free = temp;
	}
}
