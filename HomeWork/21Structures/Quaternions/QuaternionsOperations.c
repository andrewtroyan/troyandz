#include "QuaternionsOperations.h"

void enterQuaternion(Quaternion *pointer)
{
    scanf("%lf + i * %lf + j * %lf + k * %lf", &pointer->realNumber, &pointer->i, &pointer->j, &pointer->k);
}

void showQuaternion(Quaternion number)
{
    printf("%.1lf + i * %.1lf + j * %.1lf + k * %.1lf", number.realNumber, number.i, number.j, number.k);
}

void showMatingQuaternion(Quaternion number)
{
    printf("%.1lf - i * %.1lf - j * %.1lf - k * %.1lf", number.realNumber, number.i, number.j, number.k);
}

Quaternion summarize(Quaternion number1, Quaternion number2) // (w1 + i * x1 + j * y1 + k * z1) + (w2 + i * x2 + j * y2 + k * z2) = (w1 + w2) + i * (x1 + x2) + j * (y1 + y2) + k * (z1 + z2)
{
    Quaternion result;
    result.realNumber = number1.realNumber + number2.realNumber;
    result.i = number1.i + number2.i;
    result.j = number1.j + number2.j;
    result.k = number1.k + number2.k;
    return result;
}

Quaternion deduct(Quaternion number1, Quaternion number2) // (w1 + i * x1 + j * y1 + k * z1) - (w2 + i * x2 + j * y2 + k * z2) = (w1 - w2) + i * (x1 - x2) + j * (y1 - y2) + k * (z1 - z2)
{
    Quaternion result;
    result.realNumber = number1.realNumber - number2.realNumber;
    result.i = number1.i - number2.i;
    result.j = number1.j - number2.j;
    result.k = number1.k - number2.k;
    return result;
}

//Complex multiply(Complex number1, Complex number2)
//{
//}

//Complex divide(Complex number1, Complex number2)
//{
//}

Quaternion mate(Quaternion number)
{
    Quaternion result = number;
    result.i *= (-1);
    result.j *= (-1);
    result.k *= (-1);
    return result;
}
