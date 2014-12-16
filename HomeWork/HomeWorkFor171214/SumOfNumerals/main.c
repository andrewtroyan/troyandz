#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, sumOfNumerals = 0;
    printf("Enter the number: ");
    scanf("%d", &number);
    while (number)
    {
        sumOfNumerals += number % 10;
        number /= 10;
    }
    printf("The sum of numerals is %d.", sumOfNumerals);
    return 0;
}
