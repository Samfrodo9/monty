#include "monty.h"

/**
 * mod - computes the rest division of second top by top element
 * @strings: array of strings
 * @file: file to read from
 * @buffer: stream where tokens are stored
 * @line: line number
 *
 * Return: 0 on success
 */

int mod(int line, FILE *file, char *buffer, char **strings)
{
	stack_t *last;
	stack_t *previous;

	if ((!head) || (head->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
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

	if (last->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		cleanup(file, buffer, strings);
		exit(EXIT_FAILURE);
	}


	previous->n = previous->n % last->n;
	previous->next = NULL;

	free(last);
	free_tokens(strings);

	return (0);
}

