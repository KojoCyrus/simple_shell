#include "shell.h"

/**
 *cmmdexe - a function that executes the parsed input
 *@parsedtext: this is the parsed user input
 *
 *Return: should return 1 on success
*/`
int cmmdexe(char **parsedtext)
{
	pid_t pid;
	PathInfo pathinfo;
	int a;
	int status;

	checkComment(parsedtext);
	pathinfo = checkInPath(parsedtxt[0]);

	if (pathinfo.exists)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error: fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			for (i = 0; parsedtext[i] != NULL; i++)
			{
				parsedtext[i] = replaceVar(parsedtext[i], status);
			}
			if (execve(pathinfo.fullpath, parsedtext, environ) == -1)
				print_err(parsedtext[0], " :command not found\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
		return (1);
	}
	else
	{
		if (parsedtext[0] == NULL || *parsedtext[0] == '\0')
			return (127);
		return (shellBuildIn(parsedtext));
	}
}
