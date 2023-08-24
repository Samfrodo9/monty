#include "monty.h"

/**
 * main - The main program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
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
/*			printf("%d: %s", line, buffer); */
			strings = _strtok(buffer);
/*			print_token(strings); */
			if (strcmp("pall", strings[0]) == 0)
				pall();
			else if (strcmp("push", strings[0]) == 0)
				push(strings, line);
			else if (strcmp("pint", strings[0]) == 0)
				pint(strings, line);
			else if (strcmp("pop", strings[0]) == 0)
				pop(line);
			else if (strcmp("swap", strings[0]) == 0)
				swap(strings, line);
			else if (strcmp("add", strings[0]) == 0)
				add(strings, line);
			else if (strcmp("nop", strings[0]) == 0)
				nop();
			else
			{
				printf("L%d: unknown instruction %s\n", line, strings[0]);
				exit(EXIT_FAILURE);
			}

			/* Remember to Call the functions here and pass strings */
			line++;
		}
	}
	else
		usage();
	fclose(file);
	free(buffer);
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

