#include "monty.h"

/**
 * sub - subtracts the last two elements of a stack
 * @strings: array of strings
 * @file: file to read from
 * @buffer: stream where tokens are stored
 * @line: line number
 *
 * Return: 0 on success
 */

int sub(int line, FILE *file, char *buffer, char **strings)
{
	stack_t *last;
	stack_t *previous;

	if ((!head) || (head->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
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

	previous->n = previous->n - last->n;
	previous->next = NULL;

	free(last);

	return (0);
}

