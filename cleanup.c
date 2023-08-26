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
/*		printf("Clean up file\n"); */
		fclose(file);
	}

	/* Free the buffer if it's allocated */
	if (buffer)
	{
/*		 printf("Clean up buffer\n"); */
		free(buffer);
		buffer = NULL;
	}

    /* Free the tokenized strings if they're allocated */
	if (strings)
	{
/*		 printf("Clean up strings\n"); */
		free_tokens(strings);
		strings = NULL;
	}

/*	int i = 0; */
	/* Free the stack node of head */
	while (head)
	{
/*		if (i == 0) */
/*			 printf("Clean up head\n"); */
		stack_t *temp = head;
		head = head->next;
		free(temp);
/*		i++; */
	}
	head = NULL;
}



void free_head(stack_t *head)
{
	while (head)
	{
		stack_t *temp = head;
		head = head->next;
		free(temp);
	}
}

