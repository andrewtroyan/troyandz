#include <assert.h>
#include "../../../modules/include/array.h"

int maxEvenNumber(const int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int maxEvenNumber = maxOfArray(array, sizeOfPart);
    if(maxEvenNumber % 2 == 0)
    {
        return maxEvenNumber;
    }
    else
    {
        maxEvenNumber = minOfArray(array, sizeOfPart);
        for(int i = 0; i < sizeOfPart; ++i)
        {
            array[i] % 2 == 0? (maxEvenNumber = array[i] > maxEvenNumber? array[i] : maxEvenNumber) : 0;
        }
        assert(maxEvenNumber % 2 == 0);
        return maxEvenNumber;
    }
}
