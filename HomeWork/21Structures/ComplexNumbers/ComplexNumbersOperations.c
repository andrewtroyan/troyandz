#include "ComplexNumbersOperations.h"

void enterComplexNumber(Complex *pointer)
{
    scanf("%lf + i * %lf", &pointer->realNumber, &pointer->imaginaryNumber);
}

void showComplexNumber(Complex number)
{
    if(number.realNumber && number.imaginaryNumber)
    {
        printf("%.3f + i * %.3f\n", number.realNumber, number.imaginaryNumber);
    }
    if(number.realNumber && number.imaginaryNumber == 0)
    {
        printf("%.3f", number.realNumber);
    }
    if(number.realNumber == 0 && number.imaginaryNumber)
    {
        printf("i * %.3f\n", number.imaginaryNumber);
    }
    else if(number.realNumber == 0 && number.imaginaryNumber == 0)
    {
        printf("%d", 0);
    }

}

void showMatingNumber(Complex number)
{
    printf("%.3f - i * %.3f\n", number.realNumber, fabs(number.imaginaryNumber));
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
