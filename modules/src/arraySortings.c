#include <stdio.h>
#include <stdlib.h>
#include "../include/arraySortings.h"
#include <time.h>

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
        mergeSorting(ar, l, (r + l) / 2);
        mergeSorting(ar, (r + l) / 2 + 1, r);
        int br[SIZE], cr[SIZE], sizeOfBr = (r + l) / 2 - l + 1, sizeOfCr = r - (r + l) / 2;
        for(int j = 0, i = l; i <= (r + l) / 2; ++j, ++i)
        {
            br[j] = ar[i];
        }
        for(int k = 0, i = (r + l) / 2 + 1; i <= r; ++k, ++i)
        {
            cr[k] = ar[i];
        }
        int i = l, j = 0, k = 0;
        while(j < sizeOfBr && k < sizeOfCr)
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
        while(j < sizeOfBr || k < sizeOfCr)
        {
            while(j < sizeOfBr)
            {
                ar[i] = br[j];
                ++j;
                ++i;
            }
            while(k < sizeOfCr)
            {
                ar[i] = cr[k];
                ++k;
                ++i;
            }
        }
    }
}

void sortQuick(int array[], int indexOfTheStart, int indexOfTheEnd)
{
    srand(time(NULL));
    if(indexOfTheStart < indexOfTheEnd)
    {
        int temporaryIndex = rand() % (indexOfTheEnd - indexOfTheStart + 1) + indexOfTheStart, temporaryElement = array[temporaryIndex];
        array[temporaryIndex] = array[indexOfTheEnd];
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
        sortQuick(array, indexOfTheStart, i - 1);
        sortQuick(array, i + 1, indexOfTheEnd);
    }
}

void repairPyramid(int array[], int index, int sizeOfPyramid)
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
        repairPyramid(array, ancestor, sizeOfPyramid);
    }
}

void buildPyramid(int array[], int sizeOfPyramid)
{
    for(int i = sizeOfPyramid / 2; i >= 0; --i)
    {
        repairPyramid(array, i, sizeOfPyramid);
    }
}

void sortPyramid(int array[], int indexOfTheStart, int indexOfTheEnd)
{
    int sizeOfPyramid = indexOfTheEnd - indexOfTheStart + 1;
    buildPyramid(array, sizeOfPyramid);
    for(int i = sizeOfPyramid - 1; i >= 1; --i)
    {
        int temporary = array[0];
        array[0] = array[i];
        array[i] = temporary;
        --sizeOfPyramid;
        repairPyramid(array, 0, sizeOfPyramid);
    }
}
