#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, indicator = 0;
    printf("Enter the number >= 2: ");
    scanf("%d", &number);
    for (int i = 2; i < number; ++i)
    {
        if(number%i == 0)
        {
            indicator = 1;
        }
    }
    if (indicator)
    {
        printf("The number is not prime.");
    }
    else
    {
        printf("The number is prime.");
    }
    return 0;
}
