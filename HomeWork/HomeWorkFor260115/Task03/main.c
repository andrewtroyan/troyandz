#include <stdio.h>
#include <stdlib.h>
#include "../Task01/numberFunctions.h"

void combinateNumber(int number);

int main()
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    combinateNumber(number);
    return 0;
}

void combinateNumber(int number)
{
    if(amountOfDigitsInNumber(number) == 2)
    {
        printf("%d\n%d", number, cycleShift(number));
    }
    else
    {

    }
}
