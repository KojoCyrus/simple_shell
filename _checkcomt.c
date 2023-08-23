#include "shell.h"

/**
 *_checkcomt - a function that checks if the user typed #
 *@parsetext: this is the user input parsed
*/
void _checkcomt(char **parsetext)
{
	while (*parsetext != NULL)
	{
		if ((*parsetext)[0] == '#')
		{
			*parsetext = NULL;
			return;
		}
		parsetext++;
	}
}

