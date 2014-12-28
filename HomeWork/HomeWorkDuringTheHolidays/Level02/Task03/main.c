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
    while (indicator != 0)
    {
        duoDecimalNumber = decimalNumber / indicator;
        switch (duoDecimalNumber)
        {
        case 0:
            printf("0");
            break;
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 6:
            printf("6");
            break;
        case 7:
            printf("7");
            break;
        case 8:
            printf("8");
            break;
        case 9:
            printf("9");
            break;
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        }
        decimalNumber %= indicator;
        indicator /= 12;
    }
    return 0;
}
