#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack
 * @line: Line number in the script
 * @file: File pointer to the script
 * @buffer: Line buffer from getline
 * @strings: Tokenized input line
 *
 * Return: 0 on success
 */
int pchar(int line, FILE *file, char *buffer, char **strings)
{
	stack_t *top;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		cleanup(file, buffer, strings);
		exit(EXIT_FAILURE);
	}

	top = head;
	while (top->next != NULL)
		top = top->next;

	if ((top->n < 0) || (top->n > 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		cleanup(file, buffer, strings);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top->n);
	free_tokens(strings);

	return (0);
}
