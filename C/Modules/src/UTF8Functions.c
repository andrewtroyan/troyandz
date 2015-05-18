#include "../include/UTF8Functions.h"

int amountOfCodePoints(char *string)
{
    int amountOfCodePoints = 0, ascii = 0x00, check = 0xC0, result;
    for(int i = 0; string[i]; ++i)
    {
        if((result = string[i] & ascii) > 0x80 || (result = string[i] & check) >= 0xC0)
            ++amountOfCodePoints;
    }
    return amountOfCodePoints;
}
