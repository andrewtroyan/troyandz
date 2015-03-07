#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber, secondNumber;
    printf("Enter the first number >= 1: ");
    scanf("%d", &firstNumber);
    printf("Enter the second number >= 1: ");
    scanf("%d", &secondNumber);
    for (int i = 1; i <= firstNumber; ++i)
    {
        if (i % 2)
        {
            for (int k = 1; k <= secondNumber; ++k)
            {
                printf("%c", k % 2? '*' : ' ');
            }
        }
        else
        {
            for (int k = 1; k <= secondNumber; ++k)
            {
                printf("%c", k % 2? ' ' : '*');
            }
        }
        printf("\n");
    }
    return 0;
}
