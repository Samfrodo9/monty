#include "monty.h"

/**
 * free_tokens - Function to free the memory allocated by _strtok.
 * @tokens: tokens to free.
 */

void free_tokens(char **tokens)
{
	unsigned int i;

	if (!tokens)
		return;
	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
/*	tokens = NULL; */
}

/**
 * print_token - A function to print an array of strings
 * @token: strings to print
 */

void print_token(char **token)
{
	if (token)
	{
		int i = 0;

		while (token[i] != NULL)
		{
			printf("token[%d] = %s\n", i, token[i]);
			i++;
		}
	}
}

/**
 * malloc_error - A function to print malloc error
 *
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
