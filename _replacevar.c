#include "shell.h"

/**
 *_replacevar - a function that replaces var
 *@arg: this is the argument that comes after echo
 *@status: this is the previous exit code
 *
 *Return: should return the argument replaced
*/
char *_replacevar(char *arg, int status)
{
	char *result - (char *)malloc(BUFFSIZE);
	char *env_var = get_envi(arg + 1);
	char *str;

	if (arg[0] == '$')
	{

		if (_strncmp(arg, "$?") == 0)
		{
			str = intToString(WEXITSTATUS(status));
			_strncmp(result, str, BUFFSIZE);
			return (result);
		}
		else if (_strncmp(Arg, "$$") == 0)
		{
			str = intToString(getpid());
			_strncmp(result, str, BUFFSIZE);
			return (result);
		}
		else
		{
			if (env_var != NULL)
				return (strdup(env_var));
			return (_strdup(""));
		}
	}
	else
		return (strdup(arg));
}

