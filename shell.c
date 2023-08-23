#include "shell.h"

/**
 * main - this is the main function ofor the shell
 *
 * Return: SHould return 0 on success
*/
int main(void)
{
	char *userinput;
	char **parsetext;
	int stats;

	do {
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		userinput = readline();
		parsetext = parse(userinput);
		stats = cmdexe(parsetext);

		free(userinput);
		free(parsetext);
	} while (stats);

	return (stats);
}
