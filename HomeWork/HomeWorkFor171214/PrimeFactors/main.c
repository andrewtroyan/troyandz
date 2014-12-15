#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter the number >= 2: ");
    scanf("%d", &number);
    printf("%d = ", number);
    int i = 2;
    while(i <= number)
    {
        while(number%i == 0)
        {
            printf("%d*", i);
            number /= i;
        }
        ++i;
    }
    printf("\b.");
    return 0;
}
