#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, exponent;
    printf("Enter the number >= 2: ");
    scanf("%d", &number);
    printf("%d = ", number);
    for(int i = 2; i <= number; ++i)
    {
        if (number%i == 0)
        {
            for(exponent = 0; number%i == 0; ++exponent)
            {
                number /= i;
            }
            printf("(%d^%d)*", i, exponent);
        }
    }
    printf("\b.");
    return 0;
}
