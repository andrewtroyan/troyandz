#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    long long int factorialFirst = 1, factorialSecond, factorialThird;
    for (int i = 0; i <= number; ++i)
    {
        factorialFirst *= i > 0? i : 1;
        factorialSecond = 1, factorialThird = factorialFirst;
        for (int j = 0; j <= i; ++j)
        {
            factorialSecond *= j > 0? j : 1;
            factorialThird /= j > 0? (i - j + 1) : 1;
            printf("%lld ", factorialFirst / (factorialSecond * factorialThird));
        }
        printf("\n");
    }
    return 0;
}
