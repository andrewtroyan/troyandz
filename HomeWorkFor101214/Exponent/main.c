#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, exponent;
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
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
    return 0;
}
