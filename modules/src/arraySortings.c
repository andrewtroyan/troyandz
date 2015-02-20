#include <stdio.h>
#include <stdlib.h>

int indexOfMinInArray(int array[], int indexOfTheStart, int indexOfTheEnd)
{
    int indexOfMin = indexOfTheStart;
    while(indexOfTheStart < indexOfTheEnd)
    {
        indexOfMin = array[indexOfTheStart + 1] < array[indexOfMin]? indexOfTheStart + 1 : indexOfMin;
        ++indexOfTheStart;
    }
    return indexOfMin;
}

void selectionSorting(int array[], int indexOfTheStart, int indexOfTheEnd)
{
    if(indexOfTheStart < indexOfTheEnd)
    {
        int indexOfMinElement = indexOfMinInArray(array, indexOfTheStart, indexOfTheEnd), minElement = array[indexOfMinElement];
        array[indexOfMinElement] = array[indexOfTheStart];
        array[indexOfTheStart] = minElement;
        selectionSorting(array, indexOfTheStart + 1, indexOfTheEnd);
    }
}

void bubbleSorting(int array[], int indexOfTheStart, int indexOfTheEnd)
{
    if(indexOfTheStart < indexOfTheEnd)
    {
        for(int i = indexOfTheStart; i < indexOfTheEnd; ++i)
        {
            if(array[i] > array[i + 1])
            {
                int max = array[i];
                array[i] = array[i + 1];
                array[i + 1] = max;
            }
        }
        bubbleSorting(array, indexOfTheStart, indexOfTheEnd - 1);
    }
}


