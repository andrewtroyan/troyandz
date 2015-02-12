#include <assert.h>
#include "../../../modules/include/array.h"

int lengthOfTheLongestPartWithTheSameElemenets(int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int lengthOfPartWithTheSameElements = 0, indicator;
    for(int i = 0; i < sizeOfPart; ++i)
    {
        indicator = 1;
        if(array[i] == array[i + 1])
        {
            while(array[i] == array[i + 1])
            {
                ++indicator;
                ++i;
            }
            if(indicator > lengthOfPartWithTheSameElements)
            {
                lengthOfPartWithTheSameElements = indicator;
                --i;
            }
        }
    }
    if(lengthOfPartWithTheSameElements == 0)
    {
        exit(1);
    }
    else
    {
        return lengthOfPartWithTheSameElements;
    }
}
