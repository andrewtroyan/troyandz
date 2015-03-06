#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../../modules/include/array.h"
#include "../askForGenerateOrWriting.h"
#include "../../../modules/include/compatibility.h"
#include "arrayWithArithmeticalMean.h"

int main()
{
    int firstArray[SIZE], secondArray[SIZE], sizeOfPart;
    printf("Enter the size of array (0 < size <= %d): ", SIZE);
    scanf("%d", &sizeOfPart);
    assert(sizeOfPart > 0 && sizeOfPart < SIZE);
    askForGenerateOrWriting(firstArray, sizeOfPart);
    universalClear();
    printf("Your array:\n");
    outputArrray(firstArray, sizeOfPart);
    arrayWithArithmeticalMean(firstArray, secondArray, sizeOfPart);
    printf("This is your second array:\n");
    outputArrray(secondArray, sizeOfPart);
    return 0;
}
