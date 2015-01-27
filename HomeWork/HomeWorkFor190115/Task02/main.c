#include <stdio.h>
#include <stdlib.h>
#include "numsyst.h"

int main()
{
    int decimalNumber, numberSystem;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);
    printf("Enter the number system (from 2 to 36):  ");
    scanf("%d", &numberSystem);
    if (numberSystem >= 2 && numberSystem <= 36)
    {
        printf("Your number in this number system (%d): ", numberSystem);
        toAnotherNumberSystem(decimalNumber, numberSystem);
        printf(".");
    }
    else
    {
        printf("ERROR!");
    }
    return 0;
}
