#include <stdio.h>
#include <stdlib.h>

void comparison(int a, int b, int c);

int main()
{
    int firstNumber, secondNumber, thirdNumber;
    printf("Enter three numbers with a space between them: ");
    scanf("%d", &firstNumber);
    scanf("%d", &secondNumber);
    scanf("%d", &thirdNumber);
    comparison(firstNumber, secondNumber, thirdNumber);
    return 0;
}

void comparison(int a, int b, int c)
{
    a + b > c? printf("a + b > c") : (a + b < c? printf("a + b < c") : printf("a + b = c"));
}
