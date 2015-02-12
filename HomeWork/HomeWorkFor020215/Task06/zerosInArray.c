#include <assert.h>
#include "../../../modules/include/array.h"

void showLongestZerosPart(int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int lengthOfZerosPart = 0, startOfZerosPart = 0, endOfZerosPart = 0, indicator = 0;
    for(int i = 0; i < sizeOfPart;)
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
        ++i;
    }
    printf("The first longest part with zeros takes %d elements. The index of the start: %d. The index of the end: %d.\n", lengthOfZerosPart, startOfZerosPart, endOfZerosPart);
}
