#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 */
void rotl(void)
{
	stack_t *second;
	stack_t *last;

	if (head == NULL || head->next == NULL)
	{
		return;
	}

	second = head->next;
	last = head;

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = head;
	head->prev = last;
	head->next = NULL;
	second->prev = NULL;
	head = second;
}
