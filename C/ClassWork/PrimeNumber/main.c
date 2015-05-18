#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter the number >= 2: ");
    scanf("%d", &number);
    int indicator = 0;
    for(int i = 2; i*i <= number; i++)
    {
        if(number % i == 0)
        {
            indicator = 1;
        }
    }
    if(indicator)
    {
        printf("Your number is not prime.\n");
    }
    else
    {
        printf("Your number is prime.\n");
    }
    return 0;
}
