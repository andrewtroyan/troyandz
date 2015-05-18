#include <time.h>
#include "../include/multidimensionalArray.h"

void outputMultiArray(int **array, int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
}

void fillMultiArrayWithRandomNumbers(int **array, int rows, int cols)
{
    srand(time(NULL));
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            array[i][j] = rand() % 10;
        }
    }
}

void sortMultiArray(int **array, int rows, int cols)
{
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

void shiftMultiArray(int **array, int rows, int cols, char symbol, int amountOfSteps)
{
    int *storage = NULL;
    storage = (int *)malloc(amountOfSteps * sizeof(int));
    switch(symbol)
    {
    case 'r':
        amountOfSteps %= cols;
        if(amountOfSteps == 0)
        {
            return 0;
        }
        for(int i = 0; i < rows; ++i)
        {
            for(int k = 0, j = cols - amountOfSteps; k < amountOfSteps; ++k, ++j)
            {
                storage[k] = array[i][j];
            }
            for(int j = cols - amountOfSteps - 1; j >= 0; --j)
            {
                array[i][j + amountOfSteps] = array[i][j];
            }
            for(int j = 0, k = 0; k < amountOfSteps; ++j, ++k)
            {
                array[i][j] = storage[k];
            }
        }
        break;
    case 'l':
        amountOfSteps %= cols;
        if(amountOfSteps == 0)
        {
            return 0;
        }
        for(int i = 0; i < rows; ++i)
        {
            for(int k = 0, j = 0; k < amountOfSteps; ++k, ++j)
            {
                storage[k] = array[i][j];
            }
            for(int j = 0; j < cols - amountOfSteps; ++j)
            {
                array[i][j] = array[i][j + amountOfSteps];
            }
            for(int j = cols - amountOfSteps, k = 0; k < amountOfSteps; ++j, ++k)
            {
                array[i][j] = storage[k];
            }
        }
        break;
    case 'u':
        amountOfSteps %= rows;
        if(amountOfSteps == 0)
        {
            return 0;
        }
        for(int j = 0; j < cols; ++j)
        {
            for(int k = 0, i = 0; k < amountOfSteps; ++k, ++i)
            {
                storage[k] = array[i][j];
            }
            for(int i = 0; i < rows - amountOfSteps; ++i)
            {
                array[i][j] = array[i + amountOfSteps][j];
            }
            for(int i = rows - amountOfSteps, k = 0; k < amountOfSteps; ++i, ++k)
            {
                array[i][j] = storage[k];
            }
        }
        break;
    case 'd':
        amountOfSteps %= rows;
        if(amountOfSteps == 0)
        {
            return 0;
        }
        for(int j = 0; j < cols; ++j)
        {
            for(int k = 0, i = rows - amountOfSteps; k < amountOfSteps; ++k, ++i)
            {
                storage[k] = array[i][j];
            }
            for(int i = cols - amountOfSteps - 1; i >= 0; --i)
            {
                array[i + amountOfSteps][j] = array[i][j];
            }
            for(int i = 0, k = 0; k < amountOfSteps; ++i, ++k)
            {
                array[i][j] = storage[k];
            }
        }
        break;
    }
    free(storage);
    storage = NULL;
}

