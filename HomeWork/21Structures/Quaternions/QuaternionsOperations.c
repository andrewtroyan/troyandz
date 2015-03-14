#include "QuaternionsOperations.h"

void enterQuaternion(Quaternion *pointer)
{
    char sign1, sign2, sign3;
    scanf("%lf %c i * %lf %c j * %lf %c k * %lf", &pointer->realNumber, &sign1, &pointer->i, &sign2, &pointer->j, &sign3, &pointer->k);
    pointer->i *= sign1 == '-'? -1 : 1;
    pointer->j *= sign2 == '-'? -1 : 1;
    pointer->k *= sign3 == '-'? -1 : 1;
}

void showQuaternion(Quaternion number)
{
    printf("%.1lf %c i * %.1lf %c j * %.1lf %c k * %.1lf\n", number.realNumber, getSign(number.i), fabs(number.i), getSign(number.j), fabs(number.j), getSign(number.k), fabs(number.k));
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

Quaternion multiply(Quaternion number1, Quaternion number2) // (w1 + i * x1 + j * y1 + k * z1) * (w2 + i * x2 + j * y2 + k * z2) = (w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2) +
{                                                           // + i * (w1 * x2 + w2 * x1 + y1 * z2 + y2 * z1) + j * (w1 * y2 + w2 * y1 + x1 * z2 + x2 * z1) + k * (w1 * z2 + w2 * z1 + x1 * y2 + x2 * y1)
    Quaternion result;
    result.realNumber = number1.realNumber * number2.realNumber - number1.i * number2.i - number1.j * number2.j - number1.k * number2.k;
    result.i = number1.realNumber * number2.i + number2.realNumber * number1.i + number1.j * number2.k + number2.j * number1.k;
    result.j = number1.realNumber * number2.j + number2.realNumber * number1.j + number1.i * number2.k + number2.i * number1.k;
    result.k = number1.realNumber * number2.k + number2.realNumber * number1.k + number1.i * number2.j + number2.i * number1.j;
    return result;
}

Quaternion divide(Quaternion number1, Quaternion number2) // (w1 + i * x1 + j * y1 + k * z1) / (w2 + i * x2 + j * y2 + k * z2) = ((w1 * w2 + x1 * x2 + y1 * y2 + z1 * z2) + i * (w2 * x1 - w1 * x2 - y1 * z2 - y2 * z1) +
{                                                         // j * (w2 * y1 - w1 * y2 - x1 * z2 - x2 * z1) + k * (w2 * z1 - w1 * z2 - x1 * y2 - x2 * y1)) / w2 * w2 + x2 * x2 + y2 * y2 + z2 * z2
    double temp = number2.realNumber * number2.realNumber + number2.i * number2.i + number2.j * number2.j + number2.k * number2.k;
    Quaternion result;
    result.realNumber = (number1.realNumber * number2.realNumber + number1.i * number2.i + number1.j * number2.j + number1.k * number2.k) / temp;
    result.i = (number2.realNumber * number1.i - number1.realNumber * number2.i - number1.j * number2.k - number2.j * number1.k) / temp;
    result.j = (number2.realNumber * number1.j - number1.realNumber * number2.j - number1.i * number2.k - number2.i * number1.k) / temp;
    result.k = (number2.realNumber * number1.k - number1.realNumber * number2.k - number1.i * number2.j - number2.i * number1.j) / temp;
    return result;
}

Quaternion mate(Quaternion number)
{
    Quaternion result = number;
    result.i *= (-1);
    result.j *= (-1);
    result.k *= (-1);
    return result;
}

char getSign(double number)
{
    return number >= 0? '+' : '-';
}
