#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../../modules/include/array.h"
#include "../askForGenerateOrWriting.h"
#include "../../../modules/include/compatibility.h"
#include "longestPartWithTheSameElements.h"

int main()
{
    int array[SIZE], sizeOfPart;
    printf("Enter the size of array (0 < size <= %d): ", SIZE);
    scanf("%d", &sizeOfPart);
    assert(sizeOfPart > 0 && sizeOfPart < SIZE);
    askForGenerateOrWriting(array, sizeOfPart);
    universalClear();
    printf("Your array:\n");
    outputArrray(array, sizeOfPart);
    printf("The longest part with the same elements takes %d elements.", lengthOfTheLongestPartWithTheSameElemenets(array, sizeOfPart));
    return 0;
}
