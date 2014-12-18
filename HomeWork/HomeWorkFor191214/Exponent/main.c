#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double eps, x = -2.0;
    printf("Enter the eps accuracy (for example, 0.0001 or 1e-4): ");
    scanf("%lf", &eps);
    system("cls");
    printf("%s%17s%11s%12s\n\n", "x:", "Your exp(x):", "My exp(x):", "Difference:");
    while (x < 2.1)
    {
        int i = 1;
        double result = 0.0, adding = 1.0;
        while (fabs(adding) >= eps)
        {
            result += adding;
            adding *= x / i;
            ++i;
        }
        printf("% .1f%11f%13f% 12f\n", x, result, exp(x), result - exp(x));
        x += 0.1;
    }
    return 0;
}
