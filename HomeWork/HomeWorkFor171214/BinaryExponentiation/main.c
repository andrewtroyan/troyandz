#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double number;
    int exponent, exponentAbs;
    printf("Enter the number: ");
    scanf("%lf", &number);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    double r = 1.0, q = number;
    int bit = 1;
    exponentAbs = exponent < 0? -exponent : exponent;
    while (bit <= exponentAbs)
    {
        if(bit & exponentAbs)
        {
            r *= q;
            q *= q;
        }
        else
        {
            q *= q;
        }
        bit <<= 1;
    }
    r = exponent < 0? 1.0/r : r;
    printf("The result is %.5f.", r);
    return 0;
}
