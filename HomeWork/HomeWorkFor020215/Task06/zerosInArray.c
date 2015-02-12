#include <assert.h>
#include "../../../modules/include/array.h"

void showLongestZerosPart(int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int lengthOfZerosPart = 0, startOfZerosPart = 0, endOfZerosPart = 0, indicator = 0;
    for(int i = 0; i < sizeOfPart; ++i)
    {
        indicator = 0;
        if(array[i] == 0)
        {
            while(array[i] == 0)
            {
                ++indicator;
                ++i;
            }
            if(indicator > lengthOfZerosPart)
            {
                lengthOfZerosPart = indicator;
                endOfZerosPart = --i;
                startOfZerosPart = endOfZerosPart - lengthOfZerosPart + 1;
            }
        }
    }
    if(lengthOfZerosPart == 0)
    {
        printf("There's no parts with zeros in this array.\n");
    }
    else
    {
        printf("The first longest part with zeros takes %d element(s). The index of the start: %d. The index of the end: %d.\n", lengthOfZerosPart, startOfZerosPart, endOfZerosPart);
    }
}
