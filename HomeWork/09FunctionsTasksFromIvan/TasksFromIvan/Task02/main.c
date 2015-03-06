#include <stdio.h>
#include <stdlib.h>

void devision(int a, int b);

int main()
{
    int firstNumber, secondNumber;
    printf("Enter two numbers with a space between them: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    devision(firstNumber, secondNumber);
    return 0;
}

void devision(int a, int b)
{
    a % b? printf ("a!/b\n") : printf("a/b\n");
    b % a? printf ("b!/a\n") : printf("b/a\n");
}

