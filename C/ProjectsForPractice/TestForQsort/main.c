#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/array.h"

int func(const void *a, const void *b);

int main()
{
    int *array = NULL, size;
    fprintf(stdout, "Enter the size of array: ");
    fscanf(stdin, "%d", &size);
    array = (int *)malloc(size * sizeof(int));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    generateRandomNumbersInArray(array, size, 0, 99);
    fprintf(stdout, "This is your array:\n");
    outputArray(array, size);
    qsort(array, size, sizeof(int), func);
    fprintf(stdout, "This is your sorted array:\n");
    outputArray(array, size);
    return 0;
}

int func(const void *a, const void *b)
{
    return *((const int *)a) - *((const int *)b);
}
