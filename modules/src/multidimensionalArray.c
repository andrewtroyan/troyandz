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

void shiftMultiArray(int array[][MAXCOLS], int rows, int cols, char symbol, int amountOfSteps)
{
    int storage[amountOfSteps];
    switch(symbol)
    {
    case 'r':
        amountOfSteps = amountOfSteps % cols;
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
        amountOfSteps = amountOfSteps % cols;
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
        amountOfSteps = amountOfSteps % rows;
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
        amountOfSteps = amountOfSteps % rows;
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
}

