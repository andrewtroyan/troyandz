#include <stdio.h>
#include <stdlib.h>

int main()
{
    int decimalNumber, duoDecimalNumber;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);
    int indicator = 1;
    while (indicator <= decimalNumber)
    {
        indicator *= 12;
    }
    indicator /= 12;
    printf("Your number in the duodecimal number system: ");
    while (indicator != 0)
    {
        duoDecimalNumber = decimalNumber / indicator;
        switch (duoDecimalNumber)
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        default:
            printf("%d", duoDecimalNumber);
        }
        decimalNumber %= indicator;
        indicator /= 12;
    }
    printf(".");
    return 0;
}
