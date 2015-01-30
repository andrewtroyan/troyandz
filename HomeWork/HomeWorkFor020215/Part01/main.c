#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/array.h"
#include "../../../ClassWork/Task280115/searchArray.h"
#include "../askForGenerateOrWriting.h"
#include "interchangeFirstPositiveAndLastNegative.h"
#include "../../../modules/include/compatibility.h"

int main()
{
    int array[SIZE], sizeOfPart;
    printf("Enter the size of array (0 < size <= %d): ", SIZE);
    scanf("%d", &sizeOfPart);
    askForGenerateOrWriting(array, sizeOfPart);
    universalClear();
    printf("Your array:\n");
    outputArrray(array, sizeOfPart);
    interchangeFirstPositiveAndLastNegative(array, sizeOfPart);
    return 0;
}
