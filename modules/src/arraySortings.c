#include <stdlib.h>
#include <math.h>
#include "../include/arraySortings.h"

int indexOfMinInArray(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    int indexOfMin = indexOfTheStart;
    while(indexOfTheStart < indexOfTheEnd)
    {
        indexOfMin = array[indexOfTheStart + 1] < array[indexOfMin]? indexOfTheStart + 1 : indexOfMin;
        ++indexOfTheStart;
    }
    return indexOfMin;
}

void selectionSorting(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    for(int i = indexOfTheStart; i < indexOfTheEnd; ++i)
    {
        int indexOfMinElement = indexOfMinInArray(array, i, indexOfTheEnd), minElement = array[indexOfMinElement];
        array[indexOfMinElement] = array[i];
        array[i] = minElement;
    }
}

void bubbleSorting(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    for(int i = indexOfTheStart; i < indexOfTheEnd; ++i)
    {
        for(int j = 0; j < indexOfTheEnd - i; ++j)
        {
            if(array[j] > array[j + 1])
            {
                int max = array[j];
                array[j] = array[j + 1];
                array[j + 1] = max;
            }
        }
    }
}

void insertionShifting(int *array, int base, int indexOfTheStart, int indexOfTheEnd)
{
    if(indexOfTheStart >= base && indexOfTheStart <= indexOfTheEnd)
    {
        while(indexOfTheStart > base && array[indexOfTheStart] < array[indexOfTheStart - 1])
        {
            int min = array[indexOfTheStart];
            array[indexOfTheStart] = array[indexOfTheStart - 1];
            array[indexOfTheStart - 1] = min;
            --indexOfTheStart;
        }
        insertionShifting(array, base, indexOfTheStart + 1, indexOfTheEnd);
    }
}

void insertionSorting(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    int base = indexOfTheStart;
    insertionShifting(array, base, indexOfTheStart, indexOfTheEnd);
}

void mergeImplementation(int *array, int *temporaryArray, int indexOfTheStart, int indexOfTheEnd)
{
    if(indexOfTheStart < indexOfTheEnd)
    {
        mergeImplementation(array, temporaryArray, indexOfTheStart, (indexOfTheEnd + indexOfTheStart) / 2);
        mergeImplementation(array, temporaryArray, (indexOfTheEnd + indexOfTheStart) / 2 + 1, indexOfTheEnd);
        int i, j, k;
        for(i = indexOfTheStart; i <= (indexOfTheEnd + indexOfTheStart) / 2; ++i)
        {
            temporaryArray[i] = array[i];
        }
        for(i = (indexOfTheEnd + indexOfTheStart) / 2 + 1; i <= indexOfTheEnd; ++i)
        {
            temporaryArray[i] = array[i];
        }
        i = indexOfTheStart, j = indexOfTheStart, k = (indexOfTheEnd + indexOfTheStart) / 2 + 1;
        while(j <= (indexOfTheEnd + indexOfTheStart) / 2 && k <= indexOfTheEnd)
        {
            if(temporaryArray[j] < temporaryArray[k])
            {
                array[i] = temporaryArray[j];
                ++j;
            }
            else
            {
                array[i] = temporaryArray[k];
                ++k;
            }
            ++i;
        }
        while(j <= (indexOfTheEnd + indexOfTheStart) / 2)
        {
            array[i] = temporaryArray[j];
            ++j;
            ++i;
        }
        while(k <= indexOfTheEnd)
        {
            array[i] = temporaryArray[k];
            ++k;
            ++i;
        }
    }
}

void mergeSorting(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    int *temporaryArray = (int *)malloc((indexOfTheEnd - indexOfTheStart + 1) * sizeof(int));
    mergeImplementation(array, temporaryArray, indexOfTheStart, indexOfTheEnd);
    free(temporaryArray);
}

void quickSorting(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    if(indexOfTheStart < indexOfTheEnd)
    {
        int a = indexOfTheStart, b = (indexOfTheStart + indexOfTheEnd) / 2, c = indexOfTheEnd, indexOfMedian = b;
        if((array[a] > array[c] && array[a] < array[b]) || (array[a] > array[b] && array[a] < array[c]))
        {
            indexOfMedian = a;
        }
        else if((array[b] > array[c] && array[b] < array[a]) || (array[b] > array[a] && array[b] < array[c]))
        {
            indexOfMedian = b;
        }
        else if((array[c] > array[b] && array[c] < array[a]) || (array[c] > array[a] && array[c] < array[b]))
        {
            indexOfMedian = c;
        }
        int temporaryElement = array[indexOfMedian];
        array[indexOfMedian] = array[indexOfTheEnd];
        array[indexOfTheEnd] = temporaryElement;
        int i = indexOfTheStart;
        while(array[i] < array[indexOfTheEnd])
        {
            ++i;
        }
        for(int j = i; j < indexOfTheEnd; ++j)
        {
            if(array[j] < array[indexOfTheEnd])
            {
                int temporary = array[j];
                array[j] = array[i];
                array[i] = temporary;
                ++i;
            }
        }
        int temporary = array[i];
        array[i] = array[indexOfTheEnd];
        array[indexOfTheEnd] = temporary;
        quickSorting(array, indexOfTheStart, i - 1);
        quickSorting(array, i + 1, indexOfTheEnd);
    }
}

void pyramidicRepairing(int *array, int index, int sizeOfPyramid)
{
    int leftDescendant = 2 * index + 1, rightDescendant = 2 * index + 2, ancestor = index;
    if(leftDescendant < sizeOfPyramid && array[leftDescendant] > array[ancestor])
    {
        ancestor = leftDescendant;
    }
    if(rightDescendant < sizeOfPyramid && array[rightDescendant] > array[ancestor])
    {
        ancestor = rightDescendant;
    }
    if(ancestor != index)
    {
        int temporary = array[index];
        array[index] = array[ancestor];
        array[ancestor] = temporary;
        pyramidicRepairing(array, ancestor, sizeOfPyramid);
    }
}

void pyramidicBuilding(int *array, int sizeOfPyramid)
{
    for(int i = sizeOfPyramid / 2; i >= 0; --i)
    {
        pyramidicRepairing(array, i, sizeOfPyramid);
    }
}

void pyramidicSorting(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    int sizeOfPyramid = indexOfTheEnd - indexOfTheStart + 1;
    pyramidicBuilding(array, sizeOfPyramid);
    for(int i = sizeOfPyramid - 1; i >= 1; --i)
    {
        int temporary = array[0];
        array[0] = array[i];
        array[i] = temporary;
        --sizeOfPyramid;
        pyramidicRepairing(array, 0, sizeOfPyramid);
    }
}

int partition(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    int a = indexOfTheStart, b = (indexOfTheStart + indexOfTheEnd) / 2, c = indexOfTheEnd, indexOfMedian = b;
    if((array[a] > array[c] && array[a] < array[b]) || (array[a] > array[b] && array[a] < array[c]))
    {
        indexOfMedian = a;
    }
    else if((array[b] > array[c] && array[b] < array[a]) || (array[b] > array[a] && array[b] < array[c]))
    {
        indexOfMedian = b;
    }
    else if((array[c] > array[b] && array[c] < array[a]) || (array[c] > array[a] && array[c] < array[b]))
    {
        indexOfMedian = c;
    }
    int temporaryElement = array[indexOfMedian];
    array[indexOfMedian] = array[indexOfTheEnd];
    array[indexOfTheEnd] = temporaryElement;
    int i = indexOfTheStart;
    while(array[i] < array[indexOfTheEnd])
    {
        ++i;
    }
    for(int j = i; j < indexOfTheEnd; ++j)
    {
        if(array[j] < array[indexOfTheEnd])
        {
            int temporary = array[j];
            array[j] = array[i];
            array[i] = temporary;
            ++i;
        }
    }
    int temporary = array[i];
    array[i] = array[indexOfTheEnd];
    array[indexOfTheEnd] = temporary;
    return i;
}

void introLoop(int *array, int indexOfTheStart, int indexOfTheEnd, int depthOfRecurse)
{
    if(indexOfTheStart < indexOfTheEnd)
    {
        if(depthOfRecurse == 0)
        {
            pyramidicSorting(array, indexOfTheStart, indexOfTheEnd);
        }
        else if(depthOfRecurse > 0)
        {
            int index = partition(array, indexOfTheStart, indexOfTheEnd);
            introLoop(array, indexOfTheStart, index - 1, depthOfRecurse - 1);
            introLoop(array, index + 1, indexOfTheEnd, depthOfRecurse - 1);
        }
    }
}

void introSorting(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    int depthOfRecurse = 2 * log2(indexOfTheEnd - indexOfTheStart + 1);
    if(indexOfTheEnd - indexOfTheStart + 1 < 16)
    {
        insertionSorting(array, indexOfTheStart, indexOfTheEnd);
    }
    else
    {
        introLoop(array, indexOfTheStart, indexOfTheEnd, depthOfRecurse);
    }
}

int getMinRun(int amountOfElements)
{
    int flag = 0;
    while (amountOfElements >= 64)
    {
        flag |= amountOfElements & 1;
        amountOfElements >>= 1;
    }
    return amountOfElements + flag;
}

void timSorting(int *array, int indexOfTheStart, int indexOfTheEnd)
{
    int minRun = getMinRun(indexOfTheEnd - indexOfTheStart + 1);
    int i = indexOfTheStart - 1, sizeOfRun, startOfRun;
    do
    {
        ++i;
        startOfRun = i, sizeOfRun = 1;
        if(i == startOfRun && array[i] <= array[i + 1])
        {
            while(i < indexOfTheEnd && array[i] <= array[i + 1])
            {
                ++sizeOfRun;
                ++i;
            }
        }
        else if(i == startOfRun && array[i] > array[i + 1])
        {
            while(i < indexOfTheEnd && array[i] > array[i + 1])
            {
                ++sizeOfRun;
                ++i;
            }
            for(int k = 0; k < (i - startOfRun + 1) / 2; ++k)
            {
                int temporary = array[startOfRun + k];
                array[startOfRun + k] = array[i - k];
                array[i - k] = temporary;
            }
        }
        while(i < indexOfTheEnd && sizeOfRun < minRun)
        {
            ++i;
            ++sizeOfRun;
        }
        insertionSorting(array, startOfRun, i);
    }
    while(i < indexOfTheEnd);
}



