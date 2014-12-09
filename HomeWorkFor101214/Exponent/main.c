#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, exponent;
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
<<<<<<< HEAD
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
    printf("%.4f", result);
=======
    int result = 1;
    if(exponent > 0)
    {
        result *= number;
    }
    else if (exponent < 0)
    {
        result *= 1/result;
    }
    printf("The result is %f", result);
>>>>>>> 293125e14bbb04e138e1b4e718034c856009ea76
    return 0;
}
