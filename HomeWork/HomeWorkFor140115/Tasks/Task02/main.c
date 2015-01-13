#include <stdio.h>
#include <stdlib.h>

double binaryExponantiation(double number, int exponent);

int main()
{
    double number;
    int exponent;
    printf("Enter the number: ");
    scanf("%lf", &number);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    printf("The result is %.5f.", binaryExponantiation(number, exponent));
    return 0;
}

double binaryExponantiation(double number, int exponent)
{
    double r = 1.0, q = number;
    int bit = 1, exponentAbs = exponent < 0? -exponent : exponent;
    while (bit <= exponentAbs)
    {
        if(bit & exponentAbs)
        {
            r *= q;
        }
        q *= q;
        bit <<= 1;
    }
    return r = exponent < 0? 1.0/r : r;
}
