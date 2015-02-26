#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compatibility.h"
#include "../../../modules/include/multidimensionalArray.h"

int main()
{
    int **array = NULL, rows, cols;
    printf("Enter amount of rows: ");
    scanf("%d", &rows);

    array = (int **)malloc(rows * sizeof(int *));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    printf("Enter amount of columns: ");
    scanf("%d", &cols);

    for(int i = 0; i < rows; ++i)
    {
        array[i] = NULL;
        array[i] = (int *)malloc(cols * sizeof(int));
        if(array[i] == NULL)
        {
            for(int index = i; index > 0; --index)
            {
                free(array[index - 1]);
                array[index - 1] = NULL;
            }
            fprintf(stderr, "No free memoty.\n");
            exit(1);
        }
    }

    fillMultiArrayWithRandomNumbers(array, rows, cols);
    printf("\nThis is your array:\n\n");
    outputMultiArray(array, rows, cols);
    printf("\nTo sort it press any key...");
    getchar();
    getchar();
    sortMultiArray(array, rows, cols);
    printf("\nThis is your sorted array:\n\n");
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
