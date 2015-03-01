#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/multidimensionalArray.h"

int main()
{
    int **array = NULL, rows, cols, amountOfSteps;
    char symbol;
    printf("Enter amount of rows: ");
    scanf("%d", &rows);
    array = (int **)malloc(rows * sizeof(int *));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    printf("Enter amount of cols: ");
    scanf("%d", &cols);
    for(int i = 0; i < rows; ++i)
    {
        array[i] = NULL;
        array[i] = (int *)malloc(cols * sizeof(int));
        if(array == NULL)
        {
            for(int index = i; index > 0; --index)
            {
                free(array[index - 1]);
                array[index - 1] = NULL;
            }
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
    }
    fillMultiArrayWithRandomNumbers(array, rows, cols);
    printf("This is you array:\n");
    outputMultiArray(array, rows, cols);
    printf("Enter the direction (u - up, d - down, l - left, r - right) and amount of steps: ");
    scanf(" %c%d", &symbol, &amountOfSteps);
    shiftMultiArray(array, rows, cols, symbol, amountOfSteps);
    printf("This is your new array:\n");
    outputMultiArray(array, rows, cols);
    for(int i = 0; i < rows; ++i)
    {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
    return 0;
}
