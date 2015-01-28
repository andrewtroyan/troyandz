#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#define SIZE 1000

void outputArrray(const int array[], int size);
void inputArray(int array[], int size);
int arraySearch(int number, const int array[], int size);
int minOfArray(const int array[], int sizeOfArray, int sizeOfPart);
int maxOfArray(const int array[], int sizeOfArray, int sizeOfPart);
void generateRandomNumbersInArray(int array [], int sizeOfArray, int sizeOfPart);

#endif // ARRAY_H_INCLUDED
