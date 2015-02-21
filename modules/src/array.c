#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define SIZE 1000

void outputArray(const int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void inputArray(int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("Enter element[%d]: ", i);
        scanf("%d", &array[i]);
    }
}

int arraySearch(int number, const int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i] == number)
        {
            return i;
        }
    }
    return -1;
}

int minOfArray(const int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int min = array[0];
    for(int i = 1; i < sizeOfPart; ++i)
    {
        min = array[i] < min? array[i] : min;
    }
    return min;
}

int maxOfArray(const int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    int max = array[0];
    for(int i = 1; i < sizeOfPart; ++i)
    {
        max = array[i] > max? array[i] : max;
    }
    return max;
}

void generateRandomNumbersInArray(int array [], int sizeOfPart)
{
    srand(time(NULL));
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    for(int i = 0; i < sizeOfPart; ++i)
    {
        array[i] = rand()% 100;
    }
}


