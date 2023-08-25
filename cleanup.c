#include "monty.h"

/**
 * cleanup - Frees allocated resources and closes file.
 * @file: Pointer to the opened file.
 * @buffer: Pointer to the allocated buffer for getline.
 * @strings: Array of tokenized strings.
 */
void cleanup(FILE *file, char *buffer, char **strings)
{
    /* Close the file if it's open */
	if (file)
	{
		fclose(file);
	}

	/* Free the buffer if it's allocated */
	if (buffer)
	{
		free(buffer);
	}

    /* Free the tokenized strings if they're allocated */
	if (strings)
	{
		free_tokens(strings);
	}

	/* Free the stack node of head */
	while (head)
	{
		stack_t *temp = head;
		head = head->next;

		free(temp);
	}
}
