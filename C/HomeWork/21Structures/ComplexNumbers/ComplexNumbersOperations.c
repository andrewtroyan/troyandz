#include "ComplexNumbersOperations.h"

void enterComplexNumber(Complex *pointer)
{
    char sign;
    scanf("%lf %c i * %lf", &pointer->realNumber, &sign, &pointer->imaginaryNumber);
    pointer->imaginaryNumber *= sign == '-'? -1 : 1;
}

void showComplexNumber(Complex number)
{
    printf("%.1f %c i * %.1f\n", number.realNumber, getSign(number.imaginaryNumber), fabs(number.imaginaryNumber));
}

Complex summarize(Complex number1, Complex number2) // (x1 + i * y1) + (x2 + i * y2) = (x1 + x2) + i * (y1 + y2)
{
    Complex result;
    result.realNumber = number1.realNumber + number2.realNumber;
    result.imaginaryNumber = number1.imaginaryNumber + number2.imaginaryNumber;
    return result;
}

Complex deduct(Complex number1, Complex number2) // (x1 + i * y1) - (x2 + i * y2) = (x1 - x2) + i * (y1 - y2)
{
    Complex result;
    result.realNumber = number1.realNumber - number2.realNumber;
    result.imaginaryNumber = number1.imaginaryNumber - number2.imaginaryNumber;
    return result;
}

Complex multiply(Complex number1, Complex number2) // (x1 + i * y1) * (x2 + i * y2) = (x1x2 - y1y2) + i * (x1y2 + x2y1)
{
    Complex result;
    result.realNumber = number1.realNumber * number2.realNumber - number1.imaginaryNumber * number2.imaginaryNumber;
    result.imaginaryNumber = number1.realNumber * number2.imaginaryNumber + number2.realNumber * number1.imaginaryNumber;
    return result;
}

Complex divide(Complex number1, Complex number2) // ((x1 * x2 + y1 * y2) / (x2 * x2 + y2 * y2)) + i * ((y1 * x2 - x1 * y2) / (x2 * x2 + y2 * y2))
{
    Complex result;
    result.realNumber = (number1.realNumber * number2.realNumber + number1.imaginaryNumber * number2.imaginaryNumber) / (number2.realNumber * number2.realNumber + number2.imaginaryNumber * number2.imaginaryNumber);
    result.imaginaryNumber = (number1.imaginaryNumber * number2.realNumber - number1.realNumber * number2.imaginaryNumber) / (number2.realNumber * number2.realNumber + number2.imaginaryNumber * number2.imaginaryNumber);
    return result;
}

Complex mate(Complex number)
{
    Complex result = number;
    result.imaginaryNumber *= (-1);
    return result;
}

char getSign(double number)
{
    return number >= 0? '+' : '-';
}
