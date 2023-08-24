#include "monty.h"

/**
 * push - adds a new node at the end of the stack
 * @strings: a buffer where commands are stored
 * Return: 0 on success
 */

int push(char **strings)
{
	stack_t *current;
	stack_t *newlist;

	newlist = malloc(sizeof(stack_t));
	if (newlist == NULL)
	{
		free_tokens(strings);
		malloc_error();
	}

	newlist->n = atoi(strings[1]);
	newlist->next = NULL;

	if (head == NULL)
	{
		newlist->prev = NULL;
		head = newlist;
	}
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;

		current->next = newlist;
		newlist->prev = current;
	}

	return (0);
}
