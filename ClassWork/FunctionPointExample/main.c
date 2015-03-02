#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "../../modules/include/mathx.h"
#include "../../modules/include/array.h"

void bubbleSort(int *a, int n, bool (*less)(int, int));

int sumOfDigits(int a)
{
    a = a > 0? a : -a;
    int result = 0;
    while(a)
    {
        result += a % 10;
        a /= 10;
    }
    return result;
}

bool less(int a, int b)
{
    return sumOfDigits(a) > sumOfDigits(b);
}

int main()
{
    srand(time(NULL));
    int *array = NULL;
    array = (int *)malloc(10 * sizeof(int));
    generateRandomNumbersInArray(array, 10, 0, 15);
    outputArray(array, 10);
    bubbleSort(array, 10, less);
    outputArray(array, 10);
    free(array);
    array = NULL;
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *a, int n, bool (*less)(int, int))
{
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < n - 1; ++j)
            if(less(a[j + 1], a[j]))
                swap(&a[j], &a[j + 1]);
}




