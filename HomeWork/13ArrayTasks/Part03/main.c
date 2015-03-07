#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/array.h"
#include "../../../modules/include/compatibility.h"
#include "../askForGenerateOrWriting.h"
#include "maxEvenNumber.h"

int main()
{
    int array[SIZE], sizeOfPart, maxEvenElement;
    printf("Enter the size of array (0 < size <= %d): ", SIZE);
    scanf("%d", &sizeOfPart);
    askForGenerateOrWriting(array, sizeOfPart);
    universalClear();
    printf("Your array:\n");
    outputArrray(array, sizeOfPart);
    maxEvenElement = maxEvenNumber(array, sizeOfPart);
    for(int i = 0; i < sizeOfPart; ++i)
    {
        array[i] == maxEvenElement? array[i] = i : 0;
    }
    printf("New array:\n");
    outputArrray(array, sizeOfPart);
    return 0;
}
