#include "monty.h"

/**
 * add - add the last two elements of a stack
 * @strings: array of strings
 * @line: line number
 *
 * Return: 0 on success
 */

int add(char **strings, int line)
{
	int store;
	if ((!head) || (head->next == NULL))
	{
		fprintf(stderr, "L%d: can't add stack, stack too short\n", line);
		free_tokens(strings);
		exit(EXIT_FAILURE);
	}

	stack_t *last = head;
	stack_t *previous = NULL;

	while (last->next != NULL)
	{
		previous = last;
		last = last->next;
	}

	previous->n = previous->n + last->n;
	previous->next = NULL;

	free(last);

	return (0);
}
