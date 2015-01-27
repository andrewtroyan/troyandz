#include <stdio.h>
#include "../Task01/myRandom.h"

void randomElementsOfArray(int array[], int sizeOfArray, int sizeOfPart)

{
    if(sizeOfPart > 0 && sizeOfPart <= sizeOfArray)
    {
        for(int i = 0; i < sizeOfPart; ++i)
        {
            array[i] = myRandom();
        }
    }
    else
    {
        printf("ERROR!");
        exit(1);
    }
}
