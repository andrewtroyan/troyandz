#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/numsyst.h"

int main()
{
    int decimalNumber, numberSystem;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);
    printf("Enter the number system:  ");
    scanf("%d", &numberSystem);
    printf("Your number in this number system (%d): ", numberSystem);
    toAnotherNumberSystem(decimalNumber, numberSystem);
    printf(".");
    return 0;
}
