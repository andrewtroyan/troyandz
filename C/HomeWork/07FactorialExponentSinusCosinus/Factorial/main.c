#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, factorial = 1;
    printf("Enter the number: ");
    scanf("%d", &number);
    for(int i = 1; i <= number; ++i)
    {
        factorial *= i;
    }
    printf("Factorial of this number is %d.", factorial);
    return 0;
}
