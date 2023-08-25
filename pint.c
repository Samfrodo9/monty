#include "monty.h"

/**
 * pint - prints the last elements of a stack
 * @strings: array of strings
 * @file: file to read from
 * @buffer: commands to execute
 * @line: line number
 *
 * Return: 0 on success
 */

int pint(int line, FILE *file, char *buffer, char **strings)
{
	stack_t *transverse;


	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		cleanup(file, buffer, strings);
		exit(EXIT_FAILURE);
	}

	transverse = head;

	while (transverse->next != NULL)
		transverse = transverse->next;
	printf("%d\n", transverse->n);

	return (0);
}

