#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%s%6s\n", "Number", "Cubed");
    for (int i = 1, number = 1; i <= 17; ++i, number += 2)
    {
        int result = 1;
        for (int k = 1; k <= 3; ++k)
        {
            result *= number;
        }
        printf("%-7d%d\n", number, result);
    }
    return 0;
}
