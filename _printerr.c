#include "shell.h"

/**
 *_printerr - a function that prints a message tot he standard error
 *@cmmd: this is the command name
 *@text: this is the erros messahe to be printed
*/
void _printerr(char *cmmd, char *text)
{
	int a;

	if (cmmd != NULL)
	{
		a = 0;
		while (cmmd[a] != '\0')
		{
			write(2, &cmmd[a], 1);
			a++;
		}
	}
	if (text != NULL)
	{
		a = 0;
		while (text[a] != '\0)
		{
			write(2, &text[a], 1);
			a++;
		}
	}
}
