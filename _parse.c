#include "shell.h"

/**
 *parse - a function that parses the enteres line to the user
 *@line: is the line entered
 *
 *Return: NULL
*/
char **parse(char *line)
{
	int size = BUFFSIZE;
	int position = 0;
	char **token = malloc(sizeof(char *) * size);
	char *token;

	if (tokens == NULL)
	{
		print_err(NULL, "Error: malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	do {
		tokens[position] = token;
		position++;

		if (position >= size)
		{
			size += BUFFSIZE;
			tokens = realloc(tokens, size * sizeof(char *));
			if (tokens == NULL)
			{
				print_err(NULL, "Error: realloc");
				exit (EXIT_FAILURE);
			}
		}
	} while ((token = strtok(NULL, DELIM)));
	tokens[positions] = NULL;

	return (tokens);
}
