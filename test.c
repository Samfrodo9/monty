#include "monty.h"

char **_strtok(int line, FILE *file, char *buffer)
{
    char *delim = " \n\t";
    char **strings = NULL;
    char *temp = NULL, *copy = NULL;
    int i = 0, j = 0, num_tokens = 0, test = 0;

	test = line;
	test++;

    if (!buffer)
        return NULL;

    copy = strdup(buffer);
    if (!copy)
	{
		fclose(file);
		free(buffer);
        malloc_error();
	}

    temp = strtok(copy, delim);
    while (temp != NULL && num_tokens < 3)
    {
        num_tokens++;
        temp = strtok(NULL, delim);
    }

    strings = malloc(sizeof(char *) * (num_tokens + 1));
    if (!strings)
    {
		free(strings);
        free(copy);
		fclose(file);
		free(buffer);
        malloc_error();
    }

    temp = strtok(buffer, delim);
    i = 0;
    while (temp != NULL && i < num_tokens)
    {
        strings[i] = strdup(temp);
        if (!strings[i])
        {
            for (j = 0; j < i; j++)
                free(strings[j]);
            free(strings);
            free(copy);
			fclose(file);
			free(buffer);
            malloc_error();
        }
        i++;
        temp = strtok(NULL, delim);
    }
    strings[i] = NULL;
    free(copy);  /* Free the copy of the buffer */
    return strings;
}
