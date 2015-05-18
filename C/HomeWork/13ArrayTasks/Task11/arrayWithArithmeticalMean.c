#include <assert.h>
#include "../../../modules/include/array.h"

void arrayWithArithmeticalMean(int firstArray[], int secondArray[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int sum = 0, amount = 0;
    for(int i = 0; i < sizeOfPart; ++i)
    {
        sum += firstArray[i];
        ++amount;
        secondArray[i] = sum / amount;
    }
}
