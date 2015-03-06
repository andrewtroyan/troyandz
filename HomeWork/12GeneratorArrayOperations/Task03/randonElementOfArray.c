#include <stdio.h>
#include <assert.h>
#include "../Task01/myRandom.h"
#include "../../../modules/include/array.h"

void randomElementsOfArray(int array[], int sizeOfArray, int sizeOfPart)

{
    assert(sizeOfPart > 0 && sizeOfPart <= sizeOfArray);
    for(int i = 0; i < sizeOfPart; ++i)
    {
        array[i] = myRandom() % 602 - 300;
    }
}
