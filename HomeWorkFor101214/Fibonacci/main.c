#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amount, fib3;
    printf("Enter the number (>= 0): ");
    scanf("%d", &amount);
    int fib1 = 1;
    int fib2 = 1;
    switch (amount)
    {
    case 0:
        printf("There's no Fibonacci numbers");
        break;
    case 1:
        printf("There's only one Fibonacci number: %d", fib1);
        break;
    case 2:
        printf("There are just two Fibonacci numbers: %d, %d", fib1, fib2);
        break;
    default:
        printf("Fibonacci numbers: %d, %d", fib1, fib2);
        for(int i = 3; i <=amount; ++i)
        {
            fib3 = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib3;
            printf(", %d", fib3);
        }
    }
    printf("%c", '.');

    return 0;
}
