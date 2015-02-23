#include <stdio.h>
#include <stdlib.h>
#include "numberFunctions.h"

int main()
{
    int number, digit;
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("The amount of digits is %d.\nThe first digit is %d.\nAll digits except the first is %d.\nFor realization of the fourth function enter the digit: ", amountOfDigitsInNumber(number), firstDigitInNmuber(number), allDigitsExceptFirst(number));
    scanf("%d", &digit);
    printf("The compound of the number and the digit is %d.\nThe cycle shift: %d.", compoundDigit(number, digit), cycleShift(number));
    return 0;
}

// ok
