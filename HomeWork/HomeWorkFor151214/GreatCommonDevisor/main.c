#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, max, min, minNew;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    max = num1 > num2? num1 : num2;
    min = num2 > num1? num1 : num2;
    do
    {
        minNew = max%min;
        max = min;
        min = minNew;
    } while (minNew != 0);
    printf("The great common devisor of these number is %d.", max);
    return 0;
}


