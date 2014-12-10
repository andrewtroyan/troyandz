#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amount, max, number;
    printf("Enter the number (>= 1): ");
    scanf("%d", &amount);
    printf("Enter %d numbers:\n", amount);
    scanf("%d", &max);
    int min = max;
    int i = 1;
    while (i < amount)
    {
        scanf("%d", &number);
        if (number > max)
        {
            max = number;
        }
        else if (number < min)
        {
            min = number;
        }
        ++i;
    }
    printf("The maximum is %d. And the minimum is %d.", max, min);
    return 0;
}

