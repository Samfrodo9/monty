#include "monty.h"

/**
 * pint - prints the last elements of a stack
 * @strings: array of strings
 * @line: line number
 *
 * Return: 0 on success
 */

int pint(char **strings, int line)
{
	stack_t *transverse;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	transverse = (stack_t *)malloc(sizeof(stack_t));

	if (!transverse)
	{
		free_tokens(strings);
		malloc_error();
	}

	transverse = head;

	while (transverse->next != NULL)
		transverse = transverse->next;
	printf("%d\n", transverse->n);

	free(transverse);

	return (0);
}

