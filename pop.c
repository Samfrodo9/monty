#include "monty.h"

/**
 * pop - removes the last elements of a stack
 * @line: line number
 *
 * Return: 0 on success
 */

int pop(char **strings, int line, char *buffer)
{
	stack_t *previous = NULL;
	stack_t *last = head;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pop an stack empty\n", line);
		leakage(buffer, &head);
		free_tokens(strings);
		exit(EXIT_FAILURE);
	}

	while (last->next != NULL)
	{
		previous = last;
		last = last->next;
	}

	if (previous)
		previous->next = NULL;
	else
		head = NULL;

	free(last);

	return (0);
}

