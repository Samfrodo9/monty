#include "monty.h"

/**
 * swap - swaps the last two elements of a stack
 * @strings: array of strings
 * @line: line number
 *
 * Return: 0 on success
 */

int swap(char **strings, int line, char *buffer)
{
	int store;

	stack_t *last;
	stack_t *previous;

	(void)strings;

	if ((!head) | (head->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_tokens(strings);
		leakage(buffer, &head);
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
