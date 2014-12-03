#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%s%6s\n", "Number", "Cubed");
    int number=1;

    while (number<=17)
    {
        int squared=0, cubed=0;

        for (int i=0; i<number; ++i)
        {
            squared+=number;
        }

        for (int i=0; i<number; ++i)
        {
            cubed+=squared;
        }

        printf("%-7d%d\n", number, cubed);
        number+=2;
    }
    return 0;
}
