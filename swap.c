#include "monty.h"

/**
 * swap - swaps the last two elements of a stack
 * @strings: array of strings
 * @file: stream to read from
 * @buffer: where tokens are stored
 * @line: line number
 *
 * Return: 0 on success
 */

int swap(int line, FILE *file, char *buffer, char **strings)
{
	int store;

	stack_t *last;
	stack_t *previous;

	(void)strings;

	if ((!head) | (head->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		cleanup(file, buffer, strings);
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

	free_tokens(strings);
	return (0);
}
