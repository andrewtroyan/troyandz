#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber, secondNumber, intersection=0;
    printf("Enter the first number: ");
    scanf("%d", &firstNumber);
    printf("Enter the second number: ");
    scanf("%d", &secondNumber);
    for (int i=0; i<secondNumber; ++i)
    {
        intersection+=firstNumber;
    }
    printf("%-20s%d", "The intersection is", intersection);
    return 0;
}
