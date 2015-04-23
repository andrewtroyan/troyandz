#ifndef SADDLEPOINT_H_INCLUDED
#define SADDLEPOINT_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdbool>
#include <cstdlib>
#include <ctime>

namespace array
{
void generateRandomNumbersInArray(int *array, int sizeOfPart, int down, int up);
void outputMultiArray(int **array, int rows, int cols);
int minOfArray(const int *array, int sizeOfPart);
}

namespace saddlePoint
{
int maxInCol(const int **array, int rows, int cols);
}

#endif // SADDLEPOINT_H_INCLUDED
