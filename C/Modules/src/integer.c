#include "../include/integer.h"

int amountOfSigns(int number, int base)
{
    int amount = 0;

    if(number < 0)
        ++amount;

    while(number)
    {
        ++amount;
        number /= base;
    }

    return amount;
}

int itos(char **string, int integer, int base)
{
    int lengthOfStr = amountOfSigns(integer, base);

    *string = (char *)malloc(lengthOfStr + 1);
    if(!*string)
        return 1;

    int i = 0, divider = 1;

    if(integer < 0)
    {
        (*string)[i] = 45;
        integer = abs(integer);
        ++i;
    }

    while(integer / divider > base - 1)
        divider *= base;

    while(i < lengthOfStr)
    {
        int n = integer / divider;

        if(n < 10)
            (*string)[i] = n + 48;
        else
            (*string)[i] = n + 87;

        integer %= divider;
        divider /= base;
        ++i;
    }

    return 0;
}
