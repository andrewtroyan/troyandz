#include <stdio.h>
#include <stdlib.h>
#include "../include/arraySortings.h"

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

void insertionShifting(int array[], int base, int indexOfTheStart, int indexOfTheEnd)
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

void insertionSorting(int array[], int indexOfTheStart, int indexOfTheEnd)
{
    int base = indexOfTheStart;
    insertionShifting(array, base, indexOfTheStart, indexOfTheEnd);
}

void mergeSorting(int ar[], int l, int r)
{
    if(l < r)
    {
        mergeSorting(ar, l, (l + r) / 2);
        mergeSorting(ar, (l + r) / 2 + 1, r);
        int br[SIZE], cr[SIZE];
        for(int j = 0, i = l; i <= (l + r) / 2; ++j, ++i)
        {
            br[j] = ar[i];
        }
        for(int k = 0, i = (l + r) / 2 + 1; i <= r; ++k, ++i)
        {
            cr[k] = ar[i];
        }
        int i = l, j = 0, k = 0;
        while(j <= ((l + r) / 2) - l && k <= r - ((l + r) / 2 + 1))
        {
            if(br[j] < cr[k])
            {
                ar[i] = br[j];
                ++j;
            }
            else
            {
                ar[i] = cr[k];
                ++k;
            }
            ++i;
        }
        while(j <= (l + r) / 2 - l)
        {
            ar[i] = br[j];
            ++j;
            ++i;
        }
        while(k <= r - ((l + r) / 2 + 1))
        {
            ar[i] = br[k];
            ++k;
            ++i;
        }
    }
}

void repairPyramid(int array[], int index, int indexOfTheEnd)
{
    int leftDescendant = 2 * index + 1, rightDescendant = 2 * index + 2, ancestor = index;
    if(leftDescendant < indexOfTheEnd && array[leftDescendant] > array[ancestor])
    {
        ancestor = leftDescendant;
    }
    if(rightDescendant < indexOfTheEnd && array[rightDescendant] > array[ancestor])
    {
        ancestor = rightDescendant;
    }
    if(ancestor != index)
    {
        int temporary = array[index];
        array[index] = array[ancestor];
        array[ancestor] = temporary;
        repairPyramid(array, ancestor, index);
    }
}

void buildPyramid(int array[], int indexOfTheStart, int indexOfTheEnd)
{
    for(int i = (indexOfTheEnd - indexOfTheStart + 1) / 2; i >= 0; --i)
    {
        repairPyramid(array, i, indexOfTheEnd);
    }
}

void sortPyramid(int array[], int indexOfTheStart, int indexOfTheEnd)
{
    buildPyramid(array, indexOfTheStart, indexOfTheEnd);
    for(int i = indexOfTheEnd - indexOfTheStart; i >= 1; --i)
    {
        int temporary = array[0];
        array[0] = array[i];
        array[i] = temporary;
        --indexOfTheEnd;
        repairPyramid(array, 0, indexOfTheEnd);
    }
}
