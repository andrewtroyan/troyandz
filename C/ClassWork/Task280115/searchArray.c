#include <stdio.h>
#include <assert.h>
#include "../../modules/include/array.h"

int searchLastNegativeInArray(const int *array, int sizeOfPart)
{
    for(int i = sizeOfPart - 1; i >= 0; --i)
    {
        if(array[i] < 0)
        {
            return i;
        }
    }
    return -1;
}

int searchFirstPositiveInArray(const int *array, int sizeOfPart)
{
    for(int i = 0; i < sizeOfPart; ++i)
    {
        if(array[i] > 0)
        {
            return i;
        }
    }
    return -1;
}
