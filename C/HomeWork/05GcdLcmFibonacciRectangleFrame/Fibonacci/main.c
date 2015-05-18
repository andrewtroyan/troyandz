#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Fibonacci numbers: Next/Previous: Previous/Next:\n");
    double fib1 = 1, fib2 = 0, fib3;
    for (int i = 0; i < 40; ++i)
    {
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
        printf("%18.0f%15f%15f\n", fib3, fib2 / fib1, fib1 / fib2);
    }
    printf("Next/previous numbers tend to %f and previous/next numbers tend to %f.", fib2 / fib1, fib1 / fib2);
    return 0;
}



