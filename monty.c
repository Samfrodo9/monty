#include "monty.h"

/**
 * main - The main program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	FILE *file = NULL;
	char *buffer = NULL;
	char get, check;
	int line = 1;
	ssize_t count;
	size_t size = 0;

	if (ac == 2)
	{
		file = fopen(av[1], "r");
		if (file == NULL)
			error(av[1]);
		while ((count = getline(&buffer, &size, file)) != -1)
		{
			printf("%d: %s", line, buffer);
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
 * usage - A function to print
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
