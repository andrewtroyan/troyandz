#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/array.h"
#include "../../modules/include/arraySortings.h"

int main()
{
    int *array = NULL, size;
    char answer;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    printf("Do you want to fill array or generate with random numbers? (f/g) ");
    scanf(" %c", &answer);
    switch(answer)
    {
    case 'f':
        inputArray(array, size);
        break;
    case 'g':
        generateRandomNumbersInArray(array, size);
        break;
    }
    outputArray(array, size);
    printf("Do you want to sort your array? (y/n) ");
    scanf(" %c", &answer);
    if(answer == 'y')
    {
        mergeSorting(array, 0, size - 1);
        outputArray(array, size);
    }
    free(array);
    array = NULL;
    return 0;
}
