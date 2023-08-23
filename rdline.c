#include "shell.h"

/**
 * RDline - a function that allows for input
 *
 * Return: should return the text entered by the user
*/
char *RDline(void)
{
	char *line = NULL;
	size_t buffsize = 0;

	if (getline(&line, &buffsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error: readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
