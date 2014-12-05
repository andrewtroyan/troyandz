#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%s%6s\n", "Number", "Cubed");
    int number = 1;

    while (number <= 17)
    {
        int result = 1;
        for (int i = 1; i <=3; ++i)
        {
            result *= number;
        }
        printf("%-7d%d\n", number, result);
        number += 2;
    }
    return 0;
}
