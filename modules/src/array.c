#include <stdio.h>

void outputArrray(const int array[], int size)
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

int arraySearch(int number, int array[], int size)
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
