#include <assert.h>
#include "../../../modules/include/array.h"

int amountOfElementsAppearingSeveralTimes(int array[], int sizeOfPart)
{
    int  elementsAppearingSeveralTimes[sizeOfPart], k = 0;
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
        if(indicator > 1)
        {
            int secondIndicator = 0;
            for(int l = 0; l < k; ++l)
            {
                if(array[i] == elementsAppearingSeveralTimes[l])
                {
                    ++secondIndicator;
                }
            }
            if(secondIndicator == 0)
            {
                elementsAppearingSeveralTimes[k] = array[i];
                ++k;
            }
        }
    }
    if(k)
    {
        return k;
    }
    else
    {
        exit(1);
    }
}
