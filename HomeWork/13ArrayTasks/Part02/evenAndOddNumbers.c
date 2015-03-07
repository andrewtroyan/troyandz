#include <assert.h>
#include "../../../modules/include/array.h"

int searchMaxEvenNumber(const int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int maxEvenNumber = maxOfArray(array, sizeOfPart);
    if(maxEvenNumber % 2 == 0)
    {
        return maxEvenNumber;
    }
    else
    {
        maxEvenNumber = minOfArray(array, sizeOfPart);
        for(int i = 0; i < sizeOfPart; ++i)
        {
            array[i] % 2 == 0? (maxEvenNumber = array[i] > maxEvenNumber? array[i] : maxEvenNumber) : 0;
        }
        return maxEvenNumber;
    }
}

int searchMinOddNumber(const int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int minOddNumber = minOfArray(array, sizeOfPart);
    if(minOddNumber % 2)
    {
        return minOddNumber;
    }
    else
    {
        minOddNumber = maxOfArray(array, sizeOfPart);
        for(int i = 0; i < sizeOfPart; ++i)
        {
            array[i] % 2? (minOddNumber = array[i] < minOddNumber? array[i] : minOddNumber) : 0;
        }
        return minOddNumber;
    }
}

void showMaxEvenNumber(const int array[], int sizeOfPart)
{
    int number = searchMaxEvenNumber(array, sizeOfPart);
    if(number % 2 == 0)
    {
        printf("The maximal even number in your array is %d.", number);
    }
    else
    {
        printf("There's no even number in your array.");
    }
    printf("\n");
}

void showMinOddNumber(const int array[], int sizeOfPart)
{
    int number = searchMinOddNumber(array, sizeOfPart);
    if(number % 2)
    {
        printf("The minimal odd number in your array is %d.", number);
    }
    else
    {
        printf("There's no odd number in your array.");
    }
    printf("\n");
}
