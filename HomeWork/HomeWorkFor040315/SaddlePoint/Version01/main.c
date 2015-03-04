#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "SaddlePointV1.h"
#include "../../../../modules/include/array.h"


int main()
{
    int *array = NULL, rows, cols, rowMin, colMax, start;
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
        start = i * cols;
        rowMin = minInRow(array, start, start + cols);
        for(int index = start, colIndex = 0; index < start + cols; ++index, ++colIndex)
        {
            if(array[index] == rowMin)
            {
                colMax = maxInCol(array, rows, cols, colIndex);
                if(array[index] == array[colMax * cols + colIndex])
                {
                    noSaddlePoints = false;
                    printf("The saddle point is %d [%d][%d].\n", array[index], i, colIndex);
                }
            }
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

