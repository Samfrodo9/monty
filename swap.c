#include "monty.h"

/**
 * swap - swaps the last two elements of a stack
 * @strings: array of strings
 * @line: line number
 *
 * Return: 0 on success
 */

int swap(char **strings, int line)
{
	int store;

	stack_t *last;
	stack_t *previous;

	(void)strings;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pop an stack empty\n", line);
		free_tokens(strings);
		exit(EXIT_FAILURE);
	}

	if (head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_tokens(strings);
		exit(EXIT_FAILURE);
	}

	last = head;
	previous = NULL;

	while (last->next != NULL)
	{
		previous = last;
		last = last->next;
	}

	store = previous->n;

	previous->n = last->n;
	last->n = store;

	return (0);
}
