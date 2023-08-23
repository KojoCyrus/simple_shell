#include "shell.h"

/**
 *_strngchr - a function for sting character
 *@s: is a pointer tot he string
 *@z: is a character
 *
 *Return: should return the string
*/
char *_strngchr(char *s, char z)
{
	int a;

	for (a = 0; s[a]; a++)
	{
		if (s[a] == z)
			return (s + a);
	}
	return (NULL);
}

/**
 * _strngcmp - a function that compares s1 and s2
 *@s1: this is string 1
 *@s2: this is string 2
 *
 * Return: should return  on success, or else return the difference
*/
int _strngcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}
