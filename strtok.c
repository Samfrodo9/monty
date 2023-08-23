#include "monty.h"

/**
 * _strtok - A function to split strings
 * @buffer: token to split
 *
 * Return: An array of tokenized strings
 */

char **_strtok(char *buffer)
{
	char *delim = " \n";
	char **strings = NULL;
	char *temp, *copy = NULL;
	int i = 0, j, num_tokens = 0;

	if (!buffer)
		return (NULL);
	copy = strdup(buffer);
	if (!copy)
		malloc_error();
	temp = strtok(copy, delim);
	while (temp != NULL)
	{
		num_tokens++;
		temp = strtok(NULL, delim);
	}
	free(copy);
	strings = malloc(sizeof(char *) * (num_tokens + 1));
	if (!strings)
		malloc_error();
	temp = strtok(buffer, delim); /* Tokenize the input string */
	while (temp != NULL)
	{
		strings[i] = strdup(temp);
		if (!strings[i])
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
			free(strings);
			exit(EXIT_FAILURE);
		}
		i++;
		temp = strtok(NULL, delim);
	}
	strings[i] = NULL;
	return (strings);
}

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
}

/**
 * print_token - A function to print an array of strings
 * @token: strings to print
 */

void print_token(char **token)
{
	int i = 0;

	while (token[i] != NULL)
	{
		printf("token[%d] = %s\n", i, token[i]);
		i++;
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
