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
    for(int i = 1; i<= height; ++i)
    {
        if (i == 1 || i == height)
        {
            for(int k = 1; k <= width; ++k)
            {
                if (k == width)
                {
                    printf("%c\n", '#');
                }
                else
                {
                    printf("%c", '#');
                }
            }
        }
        else
        {
            for(int k = 1; k <= width; ++k)
            {
                if(k == 1)
                {
                    printf("%c", '#');
                }
                else if(k == width)
                {
                    printf("%c\n", '#');
                }
                else
                {
                    printf("%c", ' ');
                }
            }
        }
    }
    return 0;
}
