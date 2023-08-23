#include "monty.h"

/**
 * pop - removes the last elements of a stack
 * @strings: array of strings
 * @line: line number
 *
 * Return: 0 on success
 */

int pop(char **strings, int line)
{
	if (!head)
	{
		fprintf(stderr, "L%d: can't pop an stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	stack_t *last = head;
	stack_t *previous = NULL;

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

