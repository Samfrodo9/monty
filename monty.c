#include "monty.h"

stack_t *head = NULL;

int main(int ac, char **av)
{
	FILE *file = NULL;
	char *buffer = NULL;
	int line = 1;
	ssize_t count;
	size_t size = 0;
	char **strings = NULL;


	if (ac == 2)
	{
		file = fopen(av[1], "r");
		if (file == NULL)
			error(av[1]);
		while ((count = getline(&buffer, &size, file)) != -1)
        {
			/* Trim newline character at the end of the line */
			if (count > 0 && buffer[count - 1] == '\n')
			{
				buffer[count - 1] = '\0';
			}

			if (strcmp(buffer, "") == 0)
			{
				/* Blank line, skip to next iteration */
				line++;
				continue;
			}

			strings = _strtok(buffer);

			if (strcmp("pall", strings[0]) == 0)
				pall();
			else if (strcmp("push", strings[0]) == 0)
				push(strings, line, buffer, file);
			else if (strcmp("pint", strings[0]) == 0)
				pint(strings, line, buffer, file);
			else if (strcmp("pop", strings[0]) == 0)
				pop(line);
			else if (strcmp("swap", strings[0]) == 0)
				swap(strings, line, buffer, file);
			else if (strcmp("add", strings[0]) == 0)
				add(strings, line, buffer, file);
			else if (strcmp("nop", strings[0]) == 0)
				nop();
			else
			{
				printf("L%d: unknown instruction %s\n", line, strings[0]);
				exit(EXIT_FAILURE);
			}
			line++;
		}
	}
	else
		usage();

	if (file)
		fclose(file);
	free_tokens(strings);
	leakage(buffer, &head);
	
	return (0);
}

/**
 * usage - A function to print error message
 */

void usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error - A function to print error message
 * @av: argument vector
 */
void error(char *av)
{
	fprintf(stderr, "Error: Can't open file %s\n", av);
	exit(EXIT_FAILURE);
}

void leakage(char *buffer, stack_t **head)
{
	stack_t *current = *head;

	if (buffer)
		free(buffer);

	while (current != NULL)
	{
		stack_t *temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}
