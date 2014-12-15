#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    char letter = '#';
    printf("Enter the odd number: ");
    scanf("%d", &number);
    for(int i = 1; i <= number; i += 2)
    {
        for(int k = 1; k <= i; ++k)
        {
            if(k == 1)
            {
                printf("%*c", (number - i) / 2 + 1, letter);
            }
            else
            {
                printf("%c", letter);
            }
        }
        printf("\n");
    }
    for(int i = number - 2; i >= 1; i -= 2)
    {
        for(int k = 1; k <= i; ++k)
        {
            if(k == 1)
            {
                printf("%*c", (number - i) / 2 + 1, letter);
            }
            else
            {
                printf("%c", letter);
            }
        }
        printf("\n");
    }
    return 0;
}
