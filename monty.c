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
				free(buffer);
				buffer = NULL;
				line++;
				continue;
			}
			strings = _strtok(line, file, buffer);
			if (execute(strings) == 1)
			{
				free(buffer); 
				buffer = NULL;
				line++;
				continue;
			}
			execute_instructions(line, file, buffer, strings);
			line++;
			free(buffer);
			buffer = NULL;
		}

/*		cleanup(file, buffer, strings); */
		fclose(file);
		free(buffer);
		free_head(head);

		return (0);
	}

	else
		usage();
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
