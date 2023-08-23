#include "monty.h"

/**
 * pall - prints all the elements of a stack
 *
 * Return: 0 on success
 */

int pall(char **strings)
{
	(void)strings;

	stack_t *transverse;

	if (!head)
		return (0);

	transverse = head;

	while (transverse->next != NULL)
		transverse = transverse->next;

	while (transverse !=  NULL)
	{
		printf("%d\n", transverse->n);
		transverse = transverse->prev;
	}


	return (0);
}
