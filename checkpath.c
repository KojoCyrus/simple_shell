#include "shell.h"

/**
 *absolutepath - a function that checks absolute pathname
 *@text: the text the user inputs
 *
 *Return: should return infor abu tthe path
*/
PathInfo absolutepath(char *text)
{
	PathInfo info = {0, ""};

	if (access(text, F_OK) == 0)
	{
		info.exists = 1;
		_strncpy(info.fullpath, text, BUFSIZE);
	}
	return (info);
}

/**
 *relativepath -  a function that checks for relative pathname
 *@text: this is the users command
 *
 *Rethurn: should return the info about the path
*/
PathInfo relativepath(char *text)
{
	PathInfo info = {0, ""};
	char *cwd = getcwd(NULL, 0);
	char fullpath[BUFFSIZE];
	char *str = custom_concat(cwd, text, '/');

	if (cwd == NULL)
	{
		perror("Eroor: getcwd");
		return (info);
	}
	_strncpy(fullpath, str, BUFFSIZE);
	free(cwd);
	free(str);

	if (access(fullpath, F_OK) == 0)
	{
		info.exists = 1;
		_strncpy(info.fullpath, fullpath, BUFFSIZE);
	}
	return (info);
}

/**
 *searchInPath - a function that handles other case
 *@target: user input
 *@env_path: user path
 *
 * Return: should return the info about path
*/
PathInfo searchInPath(char *target, char *env_path)
{
	PathInfo result = {0, ""};
	char *path_copy = _strdup(env_path);
	char *dir = strtok(path_copy, ":");
	char fullpath[BUFFSIZE];
	char *str;

	if (env_path != NULL)
	{
		while (dir != NULL)
		{
			str = custom_concat(dir, target, '/');
			_strncpy(fullpath, str, BUFFSIZE);
			free(str);
			if (access(fullpath, F_OK) == 0)
			{
				result.exists = 1;
				_strncpy(result.fullpath, fullpath, BUFFSIZE);
				break;
			}
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (result);
}

/**
 *checkInPath - a function that checks the users command
 *@text: the user input
 *
 *Return: should return the info about path
*/
PathInfo checkInPath(char *text)
{
	PathInfo result = {0, ""};
	char *env_path = _getenv("PATH");
	if (txt == NULL || text[0] == '\0')
		return (result);
	if (txt[0] == '/')
	{
		result = absolutepath(text);
		return (result);
	}
	else
	{
		result = relativepath(text);
		if (result.exists)
			return (result);
	}
	return (searchInPath(text, env_path));
}
