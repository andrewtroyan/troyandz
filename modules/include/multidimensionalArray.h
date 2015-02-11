#ifndef MULTIDIMENSIONALARRAY_H_INCLUDED
#define MULTIDIMENSIONALARRAY_H_INCLUDED

#define MAXROWS 100
#define MAXCOLS 100

void fillMultiArrayWithRandomNumbers(int array[][MAXCOLS], int rows, int cols);
void outputMultiArray(int array[][MAXCOLS], int rows, int cols);
void sortMultiArray(int array[][MAXCOLS], int rows, int cols);
void arrayShift(int array[][MAXCOLS], int rows, int cols, char symbol, int amountOfSteps);

#endif // MULTIDIMENSIONALARRAY_H_INCLUDED
