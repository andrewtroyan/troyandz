#include "mixedFractionsOperations.h"

int main()
{
    MixedFraction firstFraction, secondFraction, result;
    double doubleResult;
    int answer;

    printf("Instruction\nEnter a fraction in this order:\nINTEGER NUMERATOR/DENOMINATOR.\n\n"
    "Select an operation:\n1. Summarize\n2. Deduct\n3. Multiply\n4. Divide\n5. Turn to double\n\n");

    scanf("%d", &answer);
    system("clear");
    printf("Instruction\nEnter a fraction in this order:\nINTEGER NUMERATOR/DENOMINATOR.\n\n");
    switch(answer)
    {
    case 1:
        printf("Enter the first fraction: ");
        enterMixedFraction(&firstFraction);
        printf("Enter the second fraction: ");
        enterMixedFraction(&secondFraction);
        result = summarize(firstFraction, secondFraction);
        printf("The result: ");
        showMixedFraction(result);
        break;
    case 2:
        printf("Enter the first fraction: ");
        enterMixedFraction(&firstFraction);
        printf("Enter the second fraction: ");
        enterMixedFraction(&secondFraction);
        result = deduct(firstFraction, secondFraction);
        printf("The result: ");
        showMixedFraction(result);
        break;
    case 3:
        printf("Enter the first fraction: ");
        enterMixedFraction(&firstFraction);
        printf("Enter the second fraction: ");
        enterMixedFraction(&secondFraction);
        result = multiply(firstFraction, secondFraction);
        printf("The result: ");
        showMixedFraction(result);
        break;
    case 4:
        printf("Enter the first fraction: ");
        enterMixedFraction(&firstFraction);
        printf("Enter the second fraction: ");
        enterMixedFraction(&secondFraction);
        result = divide(firstFraction, secondFraction);
        printf("The result: ");
        showMixedFraction(result);
        break;
    case 5:
        printf("Enter the fraction: ");
        enterMixedFraction(&firstFraction);
        doubleResult = turnToDouble(firstFraction);
        printf("The result: %f", doubleResult);
        break;
    default:
        fprintf(stderr, "Invalid value.\n");
        exit(1);
    }

    return 0;
}
