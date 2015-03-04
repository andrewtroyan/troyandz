#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "SaddlePointV2.h"
#include "../../../../modules/include/array.h"
#include "../../../../modules/include/multidimensionalArray.h"

int main()
{
    srand(time(NULL));
    int **array = NULL, rows, cols, rowMin, colMax;
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
            free(array);
            array = NULL;
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
        generateRandomNumbersInArray(array[i], cols, 0, 99);
    }
    outputMultiArray(array, rows, cols);

    bool noSaddlePoints = true;
    for(int i = 0; i < rows; ++i)
    {
        rowMin = minOfArray(array[i], cols);
        for(int j = 0; j < cols; ++j)
        {
            if(array[i][j] == rowMin)
            {
                colMax = maxInCol(array, rows, j);
                if(array[i][j] == array[colMax][j])
                {
                    noSaddlePoints = false;
                    printf("The saddle point is %d [%d][%d].\n", array[i][j], i, j);
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

