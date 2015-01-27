#include <stdio.h>
#include <stdlib.h>
#include "randonElementOfArray.h"
#include "../../../modules/include/array.h"
#define SIZE 1024

int main()
{
    int array[SIZE];
    int partOfArray;
    printf("Enter the part (amount of elements) of the array that you want to use: ");
    scanf("%d", &partOfArray);
    randomElementsOfArray(array, SIZE, partOfArray);
    printf("The minimal element of your array is %d.\n", minOfArray(array, SIZE, partOfArray));
    printf("The maximal element of your array is %d.\n", maxOfArray(array, SIZE, partOfArray));
    return 0;
}
