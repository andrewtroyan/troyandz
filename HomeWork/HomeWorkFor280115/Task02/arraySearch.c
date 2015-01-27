#include <stdio.h>

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
