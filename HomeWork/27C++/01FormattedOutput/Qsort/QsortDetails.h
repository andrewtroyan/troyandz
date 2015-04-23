#ifndef QSORTDETAILS_H_INCLUDED
#define QSORTDETAILS_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>

namespace array
{
void generateRandomNumbersInArray(int *array, int sizeOfPart, int down, int up);
void outputArray(const int *array, int size);
int ascending(const void *a, const void *b);
int descending(const void *a, const void *b);
}

#endif // QSORTDETAILS_H_INCLUDED
