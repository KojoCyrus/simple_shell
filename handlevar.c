#include "shell.h"

/**
 *handleVar - a function that handles a special variable
 *@command: the command the user is entering
 *@status: this is the status of the exe process
 *
 *Return: should return the cmd var
*/
char *handleVar(char *command, int status)
{
	char *updatedCommand = (char *)malloc(BUFFSIZE);
	char *temp;
	int a = 0;

	while (*command != '\0')
	{
		if (*command == '$')
		{
			if (*(command + 1) == '?' || *(command + 1) == '$')
			{
				temp = intToString(WEXITSTATUS(status));
				_strncpy(updatedCommand + a, temp, BUFFSIZE - a);
				a += strlen(temp);
				free(temp);
				command += 2;
			}
			else
			{
				updatedCommand[a] = *command;
				a++;
				command++;
			}
		}
		else
		{
			updatedCommand[a] = *command;
			a++;
			command++;
		}
	}
	updatedCommand[a] = '\0';
	return (updatedCommand);
}
