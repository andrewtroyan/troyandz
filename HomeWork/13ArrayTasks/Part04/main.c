#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/array.h"
#include "../../../modules/include/compatibility.h"
#include "../askForGenerateOrWriting.h"

int main()
{
    int array[SIZE], sizeOfPart, maxElement, minElement;
    printf("Enter the size of array (0 < size <= %d): ", SIZE);
    scanf("%d", &sizeOfPart);
    askForGenerateOrWriting(array, sizeOfPart);
    universalClear();
    printf("Your array:\n");
    outputArrray(array, sizeOfPart);
    maxElement = maxOfArray(array, sizeOfPart);
    minElement = minOfArray(array, sizeOfPart);
    for(int i = 0; i < sizeOfPart; ++i)
    {
        array[i] = array[i] % 2? minElement : maxElement;
    }
    printf("New array:\n");
    outputArrray(array, sizeOfPart);
    return 0;
}
