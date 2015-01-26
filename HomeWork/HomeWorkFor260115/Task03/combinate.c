#include "../Task01/numberFunctions.h"

void permuteWithPrefix(int prefix, int number);

void permute(int number)
{
    if(amountOfDigitsInNumber(number) == 1)
    {
        printf("%d\n", number);
    }
    else
    {
        for(int i = 0; i < amountOfDigitsInNumber(number); ++i)
        {
            permuteWithPrefix(firstDigitInNmuber(number), allDigitsExceptFirst(number));
            number = cycleShift(number);
        }
    }
}

void permuteWithPrefix(int prefix, int number)
{
    if(amountOfDigitsInNumber(number) == 1)
    {
        printf("%d%d\n", prefix, number);
    }
    else
    {
        for(int i = 0; i < amountOfDigitsInNumber(number); ++i)
        {
            permuteWithPrefix(compoundDigit(prefix, firstDigitInNmuber(number)), allDigitsExceptFirst(number));
            number = cycleShift(number);
        }
    }
}


