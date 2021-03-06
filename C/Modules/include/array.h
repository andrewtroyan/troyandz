#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

void outputArray(const int *array, int size);
void inputArray(int *array, int size);
int arraySearch(int number, const int *array, int size);
int minOfArray(const int *array, int sizeOfPart);
int maxOfArray(const int *array, int sizeOfPart);
void generateRandomNumbersInArray(int *array, int sizeOfPart, int down, int up);

#endif // ARRAY_H_INCLUDED
