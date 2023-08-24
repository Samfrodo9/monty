#include "monty.h"

/**
 * execute_instruction - Execute the appropriate opcode function
 * @line: Current line number in the input file
 * @file: File pointer to the input file
 * @buffer: Line buffer from getline
 * @strings: Tokenized input line
 */

void execute_instructions(int line, FILE *file, char *buffer, char **strings)
{
	int i = 0;

	instruction_t opcode_functions[] = {
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};

	int found = 0;
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
		printf("L%d: unknown instruction %s\n", line, strings[0]);
		cleanup(file, buffer, strings);
		exit(EXIT_FAILURE);
	}

}

int execute(char **strings)
{
	int i = 0;
	int found = 0;
	code functions[] = {
		{"pall", pall},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; functions[i].op; i++)
	{
		if (strcmp(strings[0], functions[i].op) == 0)
		{
			found = 1;
			functions[i].func();
			break;
		}
	}
	return (found);
}

