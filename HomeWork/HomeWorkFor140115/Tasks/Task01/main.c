#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main()
{
    int firstNumber, secondNumber;
    printf("Enter two numbers with a space between them: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    printf("The great common divisor is %d. The least common multiply is %d.", gcd(firstNumber, secondNumber), lcm(firstNumber, secondNumber));
    return 0;
}

int lcm(int a, int b);

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    while (a % b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}



