#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compatibility.h"
#include "../../../modules/include/multidimensionalArray.h"

int main()
{
    int array[MAXROWS][MAXCOLS], rows, cols;
    printf("Enter amount of rows: ");
    scanf("%d", &rows);
    printf("Enter amount of columns: ");
    scanf("%d", &cols);
    fillMultiArrayWithRandomNumbers(array, rows, cols);
    printf("\nThis is your array:\n\n");
    outputMultiArray(array, rows, cols);
    printf("\nTo sort it press any key...");
    getchar();
    getchar();
    sortMultiArray(array, rows, cols);
    printf("\nThis is your sorted array:\n\n");
    outputMultiArray(array, rows, cols);
    return 0;
}
