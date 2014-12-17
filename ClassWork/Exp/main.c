#include <stdio.h>
#include <stdlib.h>

int main()
{
    double eps = 1e-4, x, result = 0.0, adding = 1.0;
    int i = 1;
    printf("Enter the number: ");
    scanf("%lf", &x);
    while (fabs(adding) >= eps)
    {
        result += adding;
        adding *= x / i;
        ++i;
    }
    printf("My exp = %f, exp = %f, different = %f.\n", result, exp(x), result - exp(x));
    return 0;
}
