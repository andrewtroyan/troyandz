#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    int numberTest = number, amountOfNumbers = 0;
    while (numberTest)
    {
        numberTest /= 10;
        ++amountOfNumbers;
    }
    numberTest = number;
    int numberTurned = 0, indicator = 1;
    for (int i = 1; i < amountOfNumbers; ++i)
    {
        indicator *= 10;
    }
    for (int i = 1; i <= amountOfNumbers; ++i)
    {
        numberTurned += numberTest % 10 * indicator;
        numberTest /= 10;
        indicator /= 10;
    }
    printf("%s.", number == numberTurned? "Your number is polindrom" : "Your number is not polindrom");
    return 0;
}
