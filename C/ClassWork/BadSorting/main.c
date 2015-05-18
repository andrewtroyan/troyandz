#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "../../modules/include/array.h"

#define SIZE 10

bool check(int array[], int size);
void badSorting(int array[], int size);

int main()
{
    srand(time(NULL));
    int array[SIZE];
    generateRandomNumbersInArray(array, SIZE);
    printf("Your array:\n");
    outputArray(array, SIZE);
    printf("\n");

    bool checkOfArray = check(array, SIZE);

    while(checkOfArray == false)
    {
        badSorting(array, SIZE);
        checkOfArray = check(array, SIZE);
    }

    if(checkOfArray == true)
    {
        outputArray(array, SIZE);
        printf("Your array is sorted.\n");
    }
    return 0;
}

bool check(int array[], int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        if(array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

void badSorting(int array[], int size)
{
    int one = rand() % SIZE, two = rand() % SIZE;
    int firstElement = array[one];
    array[one] = array[two];
    array[two] = firstElement;
}
