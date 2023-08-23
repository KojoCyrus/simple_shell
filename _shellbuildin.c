#include "shell.h"

/**
 *exit_shell - a function that exits shell
 *@code: the entered code
 *
 *Return: should return the code
 */
int exit_shell(char *code)
{
	int exit_code;

	if (code != NULL)
	{
		exit_code = atoi(code);
		exit(exit_code);
	}
	else
		return (0);
}

/**
 *print_env - a function that prints the env
 *
 *Return: should return 1 on success
 */
int print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
}

/**
 *change_dir - a function that changes directory
 *@dir:  the directory to change to
 *
 *Return: should return 1 on success
 */
int change_dir(char *dir)
{
	char *homedir;
	char *previousdir;

	if (dir == NULL)
	{
		homedir = get_envi("HOME");
		if (homedir != NULL)
		{
			if (chdir(homedir) != 0)
				perror("sh");
		}
		else
		_printerr(NULL, "sh: HOME environment variable not set\n");
	}
	else if (_strcmp(dir, "-") == 0)
	{
		previousdir = get_envi("OLDPWD");
		if (previousdir == NULL)
			_printerr(NULL, "sh: OLDPWD environment variable not set.\n");
		else
		{
			if (chdir(previousdir) != 0)
				perror("sh");
		}
	}
	else
	{
		if (chdir(dir) != 0)
			perror("sh");
	}

	return (1);
}
/**
 *_shellbuildin - a function that calls shell buildin command
 *@parsetext: is the command being entered by user
 *
 *Return: should return 0 or 1 on success depending on the command
 */
int _shellbuildin(char **parsetext)
{
	int a = 0;

	if (_strcmp(parsetext[0], "exit") == 0)
		a = exit_shell(parsetext[1]);
	else if (_strcmp(parsetext[0], "env") == 0)
		a = print_env();
	else if (_strcmp(parsetext[0], "cd") == 0)
		a = change_dir(parsetext[1]);
	else
	{
		_printerr("./hsh: 1: ", NULL);
		_printerr(parsetext[0], " :not found\n");
		a = 127;
	}

	return (a);
}
