#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main()
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    check(number);
    return 0;
}

void check(int number);

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    while (a % b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

void check(int number)
{
    for(int i = 1; i <= number; ++i)
    {
        for(int j = 1; j <= number; ++j)
        {
            gcd(i, j) == 1? printf("#") : printf(" ");
        }
        printf("\n");
    }
}
