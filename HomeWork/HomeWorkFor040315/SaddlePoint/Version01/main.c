#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "SaddlePointV1.h"
#include "../../../../modules/include/array.h"


int main()
{
    int *array = NULL, rows, cols;
    printf("Enter amount of rows: ");
    scanf("%d", &rows);
    printf("Enter amount of columns: ");
    scanf("%d", &cols);
    array = (int *)malloc((rows * cols) * sizeof(int));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    srand(time(NULL));
    generateRandomNumbersInArray(array, rows * cols, 0, 99);
    outputMatrix(array, rows, cols);

    bool noSaddlePoints = true;
    for(int i = 0; i < rows; ++i)
    {
        int min = minInRow(array, i, cols);
        int max = maxInCol(array, rows, cols, min);
        if(array[i * cols + min] == array[max * cols + min])
        {
            noSaddlePoints = false;
            printf("The saddle point is %d [%d][%d].\n", array[max * cols + min], max, min);
        }
    }
    if(noSaddlePoints == true)
    {
        printf("There's no saddle points.\n");
    }

    free(array);
    array = NULL;
    return 0;
}

