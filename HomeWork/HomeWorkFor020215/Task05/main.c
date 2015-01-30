#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../../modules/include/array.h"
#include "../askForGenerateOrWriting.h"
#include "../../../modules/include/compatibility.h"
#include "lastEvenPositiveNumberToTheEnd.h"

int main()
{
    int array[SIZE], sizeOfPart, number;
    printf("Enter the size of array (0 < size <= %d): ", SIZE - 1);
    scanf("%d", &sizeOfPart);
    assert(sizeOfPart > 0 && sizeOfPart < SIZE);
    askForGenerateOrWriting(array, sizeOfPart);
    universalClear();
    printf("Your array:\n");
    outputArrray(array, sizeOfPart);
    printf("Enter the number: ");
    scanf("%d", &number);
    lastEvenPositiveNumberToTheEnd(number, array, sizeOfPart);
    return 0;
}
