#include <assert.h>
#include "../../../modules/include/array.h"

int maximalSingleElementOfArray(int array[], int sizeOfPart)
{
    int singleElements[sizeOfPart], k = 0;
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    for(int i = 0; i < sizeOfPart; ++i)
    {
        int indicator = 0;
        for(int j = 0; j < sizeOfPart; ++j)
        {
            if(array[i] == array[j])
            {
                ++indicator;
            }
        }
        if(indicator == 1)
        {
            singleElements[k] = array[i];
            ++k;
        }
    }
    if(k == 0)
    {
        exit(1);
    }
    else
    {
        return maxOfArray(singleElements, k);
    }
}
