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
