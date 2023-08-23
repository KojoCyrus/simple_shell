#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>

#define DELIM " \a\n\t\r"
#define BUFFSIZE 1024

/**f
 * struct a - a function for information on path
 * @exists: shows the existence of path
 * @fullpath: is the full path
 *
 * Description: Longer descrition
*/
struct a
{
	int exists;
	char fullpath[BUFFSIZE];
};

/**
 * PathInfo - This is a typedef for struct
*/
typedef struct a PathInfo;

extern char **environ;

char *strng_cpy(char *dest, char *src, size_t n);
char *custom_concat(char *str1, char *str2, char separator);
int _strngcmp(char *s1, char *s2);
char *get_envi(const char *name);
char *_strngchr(char *s, char z);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *s);
char *_inttostr(int num);

char *RDline(void);
char **parse(char *line);
PathInfo checkInPath(char *txt);
int cmdexe(char **txt);
int _shellbuildin(char **parsetext);
char *replaceVar(char *arg, int status);
char *_getline(void);
void _checkcomt(char **command);
void _printerr(char *cmmd, char *text);
char *handleVar(char *command, int status);

#endif
