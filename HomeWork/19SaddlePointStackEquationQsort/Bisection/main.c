#include "bisectionOperations.h"

int main()
{
    float startPoint, finalPoint, eps, result;
    double *pointer;
    int answer;
    printf("Which equation do you want to run?\n1. x^3 - 2x^2 - 4x + 7 = 0\n2. e^(-x) - 0.5*sin(x)^2 = 0\n3. arccos(x) - x = 0\n");
    scanf("%d", &answer);
    switch (answer)
    {
    case 1:
        pointer = firstExample;
        break;
    case 2:
        pointer = secondExample;
        break;
    case 3:
        pointer = thirdExample;
        break;
    default:
        exit(1);
    }
    system("clear");
    printf("Enter the start point: ");
    scanf("%f", &startPoint);
    printf("Enter the final point: ");
    scanf("%f", &finalPoint);
    printf("Enter the eps: ");
    scanf("%f", &eps);
    result = bisection((double)startPoint, (double)finalPoint, (double)eps, pointer);
    printf("The result is %g ± %g.", result, eps);
    return 0;
}


