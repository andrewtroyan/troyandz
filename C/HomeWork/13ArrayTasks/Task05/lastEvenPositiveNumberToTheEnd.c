#include <assert.h>
#include "../../../modules/include/array.h"

int searchLastEvenPositiveNumber(int number, int array[], int sizeOfPart)
{
    assert(number != 0 && sizeOfPart > 0 && sizeOfPart < SIZE);
    for(int i = sizeOfPart - 1; i >= 0; --i)
    {
        if(array[i] % number == 0 && array[i] > 0)
        {
            int lastEvenPositiveNumber = array[i];
            array[i] = i;
            array[sizeOfPart] = lastEvenPositiveNumber;
            return 0;
        }
    }
    return 1;
}

void lastEvenPositiveNumberToTheEnd(int number, int array[], int sizeOfPart)
{
    if(searchLastEvenPositiveNumber(number, array, sizeOfPart))
    {
        printf("Error. There's no positive elements that even to your number.");
    }
    else
    {
        printf("New array:\n");
        outputArrray(array, sizeOfPart + 1);
    }
    printf("\n");
}
