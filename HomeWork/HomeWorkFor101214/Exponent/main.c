#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, exponent;
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    double result = 1;
    if (exponent > 0)
    {
        for (int i = 1; i <= exponent; ++i)
        {
            result *= number;
        }
    }
    else if (exponent < 0)
    {
        for (int i = -1; i >= exponent; --i)
        {
            result *= 1.0/number;
        }
    }
    printf("The result is %.4f", result);
    return 0;
}
