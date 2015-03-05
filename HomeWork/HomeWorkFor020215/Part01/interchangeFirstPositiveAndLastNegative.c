#include "../../../modules/include/array.h"
#include "../../../ClassWork/Task280115/searchArray.h"

void interchangeFirstPositiveAndLastNegative(int *array, int sizeOfPart)
{
    int indexOfFirstPositiveNumber = searchFirstPositiveInArray(array, sizeOfPart), indexOfLastNegativeNumber = searchLastNegativeInArray(array, sizeOfPart);
    if(indexOfFirstPositiveNumber >= 0 && indexOfLastNegativeNumber >= 0)
    {
        int a = array[indexOfFirstPositiveNumber], b = array[indexOfLastNegativeNumber];
        array[indexOfFirstPositiveNumber] = b;
        array[indexOfLastNegativeNumber] = a;
        printf("Your new array:\n");
        outputArray(array, sizeOfPart);
    }
    else if(indexOfFirstPositiveNumber < 0)
    {
        printf("Error. There's no positive numbers in your array.");
    }
    else
    {
        printf("Error. There's no negative numbers in your array");
    }
}
