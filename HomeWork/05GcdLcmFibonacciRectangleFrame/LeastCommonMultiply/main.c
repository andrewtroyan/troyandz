#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, max, min, excess, excess2, max2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    max = num1 > num2? num1 : num2;
    min = num2 > num1? num1 : num2;
    do
    {
        excess = max%min;
        max = min;
        min = excess;
    } while (excess != 0);
    excess2 = num1 / max;
    max2 = excess2 * num2;
    printf("The least common multiply of these numbers is %d.", max2);
    return 0;
}
