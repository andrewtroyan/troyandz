#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, sumOfNumerals = 0;
    printf("Enter the number: ");
    scanf("%d", &number);
    int decades = 1;
    while (decades <= number)
    {
        decades *= 10;
    }
    while (number)
    {
        while(decades > number)
        {
            decades /= 10;
        }
        sumOfNumerals += number/decades;
        number %= decades;
    }
    printf("The sum of numerals is %d.", sumOfNumerals);
    return 0;
}
