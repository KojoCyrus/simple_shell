#include "shell.h"

/**
 *_strncpy - c function that copies n bytes from src to dest
 *@dest: is the destination string
 *@src: is the string source
 *@n: is the nuber of bytes to copy
 *
 *Return: should return dest
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t a;

	for (a = 0; a < n && src[a] != '\0'; a++)
		dest[a] = src[a];
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}

/**
 *custom_concat - concate two stings with separator between them
 *@str1: this is the first string
 *@str2: this is the second string
 *@separator: this is the separaator
 *
 *Return: should retur the conc of the three
 */
char *custom_concat(char *str1, char *str2, char separator)
{
	size_t len1, len2, sep_len, a;
	char *result;

	len1 = len2 = 0;
	sep_len = 1;
	while (str1[len1] != '\0')
		len1++;
	while (str2[len2] != '\0')
		len2++;
	result = (char *)malloc(len1 + len2 + sep_len + 1);
	if (result == NULL)
		return (NULL);

	_strncpy(result, str1, len1);
	result[len1] = separator;
	for (a = 0; a < len2; a++)
		result[len1 + sep_len + a] = str2[a];
	result[len1 + sep_len + len2] = '\0';
	return (result);
}

/**
 *_strncmp - a function that compares n bytes of 2 strings
 *@s1: is the string 1
 *@s2: is the string 2
 *@n: number of bytes to compare
 *
 *Return: should return 0 or -15
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	for (a = 0; s1[a] && s2[a] && a < n; a++)
	{
		if (s1[a] > s2[a])
			return (s1[a] - s2[a]);
		else if (s1[a] < s2[a])
			return (s1[a] - s2[a]);
	}
	if (a == n)
		return (0);
	else
		return (-15);
}

/**
 *_strdup - a function that dupmicates string
 *@s: is a string to be duplicated
 *
 *Return: should return the resulting string
 */
char *_strdup(const char *s)
{
	int a, len = 0;
	char *new_str;

	if (s == NULL)
		return (NULL);
	while (s[len] != '\0')
		len++;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	for (a = 0; a <= len; a++)
		new_str[a] = s[a];
	return (new_str);
}

/**
 *_inttostr - a function that converts int in string
 *@num: the int to be converted
 *
 *Return: should return the string resulting from num
 */
char *_inttostr(int num)
{
	int a, len = 1;
	int temp = num;
	char *str;

	while (temp /= 10)
	{
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	a = len - 1;
	str[len] = '\0';
	while (num != 0)
	{
		str[a] = '0' + (num % 10);
		num /= 10;
		a--;
	}
	return (str);
}
