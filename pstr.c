#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack,
 * followed by a new line
 */
void pstr(void)
{
	stack_t *current = head;

	while (current && current->next)
	{
		current = current->next;
	}

	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", (char)current->n);
		current = current->prev;
	}

	printf("\n");
}
