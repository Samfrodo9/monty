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
		free_tokens(strings);
		exit(EXIT_FAILURE);
	}

	transverse = head;

	while (transverse->next != NULL)
		transverse = transverse->next;
	printf("%d\n", transverse->n);

	return (0);
}

