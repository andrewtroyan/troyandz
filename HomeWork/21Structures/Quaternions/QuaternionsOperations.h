#ifndef COMPLEXNUMBERSOPERATIONS_H_INCLUDED
#define COMPLEXNUMBERSOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Quaternion_
{
    double realNumber, i, j, k;
} Quaternion;

void enterQuaternion(Quaternion *pointer);
void showQuaternion(Quaternion number);
Quaternion summarize(Quaternion number1, Quaternion number2);
Quaternion deduct(Quaternion number1, Quaternion number2);
Quaternion multiply(Quaternion number1, Quaternion number2);
Quaternion divide(Quaternion number1, Quaternion number2);
Quaternion mate(Quaternion number);
char getSign(double);

#endif // COMPLEXNUMBERSOPERATIONS_H_INCLUDED
