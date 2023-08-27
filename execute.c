#include "monty.h"

/**
 * execute_instructions - Execute the appropriate opcode function
 * @line: Current line number in the input file
 * @file: File pointer to the input file
 * @buffer: Line buffer from getline
 * @strings: Tokenized input line
 */

void execute_instructions(int line, FILE *file, char *buffer, char **strings)
{
	instruction_t opcode_functions[] = {
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	int i, found = 0;
	char *store;

	store = strings[0];

	if (store[0] == '#')
		return;

	found = 0;
	for (i = 0; opcode_functions[i].opcode; i++)
	{
		if (strcmp(strings[0], opcode_functions[i].opcode) == 0)
		{
			opcode_functions[i].f(line, file, buffer, strings);
			found = 1;
			break;
		}
	}

	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, strings[0]);
		free_head(head);
		free_tokens(strings);
		free(buffer);
		fclose(file);
/*		buffer = NULL; */
		exit(EXIT_FAILURE);
	}
}


/**
 * execute - A function to execute commands
 * @strings: Array of strings to execute
 *
 * Return: Always 0
 */

int execute(char **strings)
{
	code functions[] = {
		{"pall", pall},
		{"nop", nop},
		{"pstr", pstr},
		{NULL, NULL}
	};

	int i, found;

	char *store = strings[0];
	if (store[0] == '#')
		return (10);

	i = 0;
	found = 0;

	for (i = 0; functions[i].op; i++)
	{
		if (strcmp(strings[0], functions[i].op) == 0)
		{
			found = 1;
			functions[i].func();
			free_tokens(strings);
			break;
		}
	}
	return (found);
}

