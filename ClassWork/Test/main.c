#include <stdio.h>
#include <stdlib.h>
#include "myfuns.h"

int main()
{
    int firstNumber, secondNumber;
    printf("Enter two numbers with a space between them: ");
    scanf("%d%d", &firstNumber, &secondNumber);
    printf("Great common divisor is %d. Least common multiply is %d.", gcd(firstNumber, secondNumber), lcm(firstNumber, secondNumber));
    return 0;
}
