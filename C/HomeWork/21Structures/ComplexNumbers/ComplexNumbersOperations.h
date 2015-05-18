#ifndef COMPLEXNUMBERSOPERATIONS_H_INCLUDED
#define COMPLEXNUMBERSOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Complex_
{
    double realNumber, imaginaryNumber;
} Complex;

void enterComplexNumber(Complex *pointer);
void showComplexNumber(Complex number);
Complex summarize(Complex number1, Complex number2);
Complex deduct(Complex number1, Complex number2);
Complex multiply(Complex number1, Complex number2);
Complex divide(Complex number1, Complex number2);
Complex mate(Complex number);
char getSign(double);

#endif // COMPLEXNUMBERSOPERATIONS_H_INCLUDED
