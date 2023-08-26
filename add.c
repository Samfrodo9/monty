#include "monty.h"

/**
 * add - add the last two elements of a stack
 * @file: file to read from
 * @buffer: commans=nds to execute
 * @strings: array of strings
 * @line: line number
 *
 * Return: 0 on success
 */

int add(int line, FILE *file, char *buffer, char **strings)
{
	stack_t *last;
	stack_t *previous;

	if ((!head) || (head->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
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

	previous->n = previous->n + last->n;
	previous->next = NULL;

	free(last);
	free_tokens(strings);
	return (0);
}
