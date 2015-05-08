#include "../include/myString.h"

int myStrlen(const char *string)
{
    int result = 0;
    while(*string++)
        ++result;
    return result;
}

int myStrcmp(const char *string1, const char *string2)
{
    while(*string1 && *string2 && *string1 == *string2)
    {
        ++string1;
        ++string2;
    }
    return *string1 - *string2;
}

char * myStrcpy(char *destination, const char *source)
{
    char *pointer = destination;
    while(*source)
    {
        *destination = *source;
        ++destination;
        ++source;
    }
    *destination = '\0';
    return pointer;
}

void mystrcat(char *dest, int amount, ...) //int amount - amount of strings to concatenate
{
    va_list list;
    va_start(list, amount);

    int n = 0;
    while(dest[n] != '\n' && dest[n] != '\0')
        ++n;

    for(int i = 0; i < amount; ++i)
    {
        char *temp = va_arg(list, char *);
        for(int j = 0; temp[j] != '\n' && temp[j] != '\0'; ++j, ++n)
            dest[n] = temp[j];
    }

    va_end(list);
}
