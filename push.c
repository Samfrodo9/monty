#include "monty.h"
/**
 * push - adds a new node at the end of the stack
 * @strings: a buffer where commands are stored
 * Return: 0 on success
 */

int push(char **strings)
{
	stack_t *copy;
	stack_t *newlist;

	newlist = malloc(sizeof(stack_t));
	if (newlist == NULL)
	{
		free_tokens(strings);
		malloc_error();
	}

	newlist->n = strings[1];
	newlist->next = NULL;

	copy = head;

	if (copy != NULL)
	{
		while (copy->next != NULL)
			copy = copy->next;
		copy->next = newlist;
	}
	else
	{
		head = newlist;
		newlist->prev = NULL;

		return (0);
	}

	newlist->prev = copy;

	return (0);
}
