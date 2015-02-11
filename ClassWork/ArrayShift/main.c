#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/multidimensionalArray.h"

int main()
{
    int array[MAXROWS][MAXCOLS], rows, cols, amountOfSteps;
    char symbol;
    printf("Enter amount of rows: ");
    scanf("%d", &rows);
    printf("Enter amount of cols: ");
    scanf("%d", &cols);
    fillMultiArrayWithRandomNumbers(array, rows, cols);
    printf("This is you array:\n");
    outputMultiArray(array, rows, cols);
    printf("Enter the direction (u - up, d - down, l - left, r - right) and amount of steps: ");
    scanf(" %c%d", &symbol, &amountOfSteps);
    arrayShift(array, rows, cols, symbol, amountOfSteps);
    printf("This is your new array:\n");
    outputMultiArray(array, rows, cols);
    return 0;
}
