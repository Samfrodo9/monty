#include "monty.h"

/**
 * pop - removes the last elements of a stack
 * @line: line number
 * @file: file to read from
 * @buffer: buffer to execute
 * @strings: array of commands
 *
 * Return: 0 on success
 */

int pop(int line, FILE *file, char *buffer, char **strings)
{
	stack_t *previous = NULL;
	stack_t *last = head;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pop an stack empty\n", line);
		cleanup(file, buffer, strings);
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
	free_tokens(strings);
	return (0);
}

