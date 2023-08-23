#include "monty.h"

/**
 * pall - prints all the elements of a stack
 *
 * Return: 0 on success
 */

int pall(char **strings)
{
	if (!head)
		return (0);

	stack_t transverse = NULL;

	transverse = (stack_t *)malloc(sizeof(stack_t));

	if (!transverse)
	{
		free_tokens(strings);
		malloc_error();
	}

	transverse = head;

	while (transverse->prev != NULL)
		transverse = transverse->prev;

	while (transverse != NULL)
	{
		printf("%d\n", transverse->n);
		transverse = transverse->next;
	}

	return (0);
}
