#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double eps, x = -2.0;
    printf("Enter the eps accuracy (for example, 0.0001 or 1e-4): ");
    scanf("%lf", &eps);
    system("cls");
    printf("%s%17s%11s%13s\n\n", "x:", "Your sin(x):", "My sin(x):", "Difference:");
    while (x < 2.1)
    {
        int i = 1;
        double result = 0.0, adding = x / i;
        while (fabs(adding) >= eps)
        {
            result += adding;
            adding *= -x * x / ((i+1) * (i+2));
            i += 2;
        }
        printf("% .1f% 12f% 13f% 12f\n", x, result, sin(x), result - sin(x));
        x += 0.1;
    }
    return 0;
}
