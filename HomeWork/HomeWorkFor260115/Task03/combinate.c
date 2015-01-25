#include "../Task01/numberFunctions.h"

void combinateNumber(int number)
{
    if(amountOfDigitsInNumber(number) == 1)
    {
        printf("%d\n", number);
    }
    else
    {
        for(int i = 0; i < amountOfDigitsInNumber(number); ++i)
        {
            number = cycleShift(number);
            printf("%d", firstDigitInNmuber(number));
            combinateNumber(allDigitsExceptFirst(number));
        }
    }
}
