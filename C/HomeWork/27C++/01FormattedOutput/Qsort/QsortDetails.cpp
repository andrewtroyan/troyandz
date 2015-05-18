#include "QsortDetails.h"

using namespace std;

void array::generateRandomNumbersInArray(int *array, int sizeOfPart, int down, int up)
{
    for(int i = 0; i < sizeOfPart; ++i)
        array[i] = rand() % (up - down + 1) + down;
}

void array::outputArray(const int *array, int size)
{
    for(int i = 0; i < size; ++i)
        cout << array[i] << ' ';
    cout << endl;
}

int array::ascending(const void *a, const void *b)
{
    return *((const int *)a) - *((const int *)b);
}

int array::descending(const void *a, const void *b)
{
    return *((const int *)b) - *((const int *)a);
}
