#include <time.h>
#include <assert.h>
#include "../include/multidimensionalArray.h"

void outputMultiArray(int array[][MAXCOLS], int rows, int cols)
{
    assert(rows > 0 && rows <= MAXROWS && cols > 0 && cols <= MAXCOLS);
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void fillMultiArrayWithRandomNumbers(int array[][MAXCOLS], int rows, int cols)
{
    assert(rows > 0 && rows <= MAXROWS && cols > 0 && cols <= MAXCOLS);
    srand(time(NULL));
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            array[i][j] = rand() % 10;
        }
    }
}

void sortMultiArray(int array[][MAXCOLS], int rows, int cols)
{
    assert(rows > 0 && rows <= MAXROWS && cols > 0 && cols <= MAXCOLS);
    int max, i, j;
    for(int k = 0; k < (rows * cols) - 1; ++k)
    {
        i = 0, j = 0;
        for(int l = 0; l < (rows * cols) - k - 1; ++l)
        {
            if(cols - j == 1)
            {
                if(array[i][j] > array[i + 1][0])
                {
                    max = array[i][j];
                    array[i][j] = array[i + 1][0];
                    array[i + 1][0] = max;
                }
                j = 0;
                ++i;
            }
            else
            {
                if(array[i][j] > array[i][j + 1])
                {
                    max = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = max;
                }
                ++j;
            }
        }
    }
}
