#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    int amountOfSpacesLeft = number + 1, amountOfSpacesBetween = 0;
    for(int i = 0; i <= number; ++i)
    {
        printf("%*c%*s%c\n", amountOfSpacesLeft, '*', amountOfSpacesBetween, "", '*');
        --amountOfSpacesLeft;
        amountOfSpacesBetween += 2;
    }
    return 0;
}
