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
    for(int i = 1; i <= exponent; ++i)
    {
        result *= number;
    }
    printf("%d ^ %d = %d\n", number, exponent, result);
    return 0;
}














