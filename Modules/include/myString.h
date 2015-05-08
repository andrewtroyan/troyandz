#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <stdarg.h>

int myStrlen(const char *);
int myStrcmp(const char *, const char *);
char * myStrcpy(char *, const char *);
void mystrcat(char *dest, int amount, ...);

#endif // MYSTRING_H_INCLUDED
