#include "shell.h"

/**
 *get_envi - this is a custom get env funtion
 *@nam: thisis the varianle we are getting in the env
 *
 *Return: should return the pointer to char
*/
char *get_envi(const char *nam)
{
	int a;
	char *equal;
	int nam_length;

	for (a = 0; environ[a] !=NULL; a++)
	{
		equal = _strchr(environ[a], '=');
		if (equal == NULL)
			continue;

		nam_length = equal - environ[a];
		if (_strncmp(environ[a], nam, nam_length) == 0)
			return (equal + 1);
	}
	return (NULL);
}
