#include "ComplexNumbersOperations.h"

int main()
{
    Complex firstComplexNumber, secondComplexNumber, result;
    int answer;

    printf("Instruction\nEnter a complex number in this order:\nREAL + i * IMAGINARY.\n\n"
    "Select an operation:\n1. Summarize\n2. Deduct\n3. Multiply\n4. Divide\n5. Mate\n\n");

    scanf("%d", &answer);
    system("clear");
    printf("Instruction\nEnter a complex number in this order:\nREAL + i * IMAGINARY.\n\n");
    switch(answer)
    {
    case 1:
        printf("Enter the first complex number: ");
        enterComplexNumber(&firstComplexNumber);
        printf("Enter the second complex number: ");
        enterComplexNumber(&secondComplexNumber);
        result = summarize(firstComplexNumber, secondComplexNumber);
        printf("The result: ");
        showComplexNumber(result);
        break;
    case 2:
        printf("Enter the first complex number: ");
        enterComplexNumber(&firstComplexNumber);
        printf("Enter the second complex number: ");
        enterComplexNumber(&secondComplexNumber);
        result = deduct(firstComplexNumber, secondComplexNumber);
        printf("The result: ");
        showComplexNumber(result);
        break;
    case 3:
        printf("Enter the first complex number: ");
        enterComplexNumber(&firstComplexNumber);
        printf("Enter the second complex number: ");
        enterComplexNumber(&secondComplexNumber);
        result = multiply(firstComplexNumber, secondComplexNumber);
        printf("The result: ");
        showComplexNumber(result);
        break;
    case 4:
        printf("Enter the first complex number: ");
        enterComplexNumber(&firstComplexNumber);
        printf("Enter the second complex number: ");
        enterComplexNumber(&secondComplexNumber);
        result = divide(firstComplexNumber, secondComplexNumber);
        printf("The result: ");
        showComplexNumber(result);
        break;
    case 5:
        printf("Enter the complex number: ");
        enterComplexNumber(&firstComplexNumber);
        result = mate(firstComplexNumber);
        printf("The result: ");
        showMatingNumber(result);
        break;
    default:
        fprintf(stderr, "Invalid value.\n");
        exit(1);
    }

    return 0;
}
