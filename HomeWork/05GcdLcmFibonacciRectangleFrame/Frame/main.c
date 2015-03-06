#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height;
    printf("Enter the width (>= 1): ");
    scanf("%d", &width);
    printf("Enter the height (>= 1): ");
    scanf("%d", &height);
    system("cls");
    for(int i = 1; i <= height; ++i)
    {
        for(int k = 1; k <= width; ++k)
        {
            if(i == 1 || i == height || k == 1 || k == width)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
