#ifndef MULTIDIMENSIONALARRAY_H_INCLUDED
#define MULTIDIMENSIONALARRAY_H_INCLUDED

void fillMultiArrayWithRandomNumbers(int **array, int rows, int cols);
void outputMultiArray(int **array, int rows, int cols);
void sortMultiArray(int **array, int rows, int cols);
void shiftMultiArray(int **array, int rows, int cols, char symbol, int amountOfSteps);

#endif // MULTIDIMENSIONALARRAY_H_INCLUDED
