#include "saddlePoint.h"

using namespace std;

void array::generateRandomNumbersInArray(int *array, int sizeOfPart, int down, int up)
{
    for(int i = 0; i < sizeOfPart; ++i)
        array[i] = rand() % (up - down + 1) + down;
}

void array::outputMultiArray(int **array, int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
            cout << setw(3) << array[i][j] << ' ';
        cout << endl;
    }
}

int array::minOfArray(const int *array, int sizeOfPart)
{
    int min = array[0];
    for(int i = 1; i < sizeOfPart; ++i)
        min = array[i] < min? array[i] : min;
    return min;
}

int saddlePoint::maxInCol(const int **array, int rows, int cols)
{
    int numberOfRow = 0;
    for(int i = 1; i < rows; ++i)
        if(array[i][cols] > array[numberOfRow][cols])
            numberOfRow = i;
    return numberOfRow;
}
