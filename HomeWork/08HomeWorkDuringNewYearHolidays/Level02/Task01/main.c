#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amountOfLayers;
    printf("Enter the amount of layers: ");
    scanf("%d", &amountOfLayers);
    system("cls");
    for (int i = 1, k = 1; i <= amountOfLayers; ++i, ++k)
    {
        printf ("%*s%c\n", amountOfLayers, "", '*');
        int amountOfSpacesLeft = amountOfLayers - 1, amountOfSpacesBetween = 1;
        for (int l = 2; l <= i; ++l)
        {
            printf("%*s%c%*s%c\n", amountOfSpacesLeft, "", '*', amountOfSpacesBetween, "", '*');
            --amountOfSpacesLeft;
            amountOfSpacesBetween += 2;
        }
        printf("%*s", amountOfLayers - k, "");
        for (int j = 1; j <= (i * 2 + 1); ++j)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
    if (amountOfLayers <= 3)
    {
        printf("%*s%c\n%*s%c", amountOfLayers, "", '*', amountOfLayers, "", '*');
    }
    else
    {
        printf("%*s%c%2c\n%*s%c%2c", amountOfLayers - 1, "", '*', '*', amountOfLayers - 1, "", '*', '*');
    }
    return 0;
}
