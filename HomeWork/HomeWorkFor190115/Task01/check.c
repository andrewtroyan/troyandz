#include "../../../modules/include/mathx.h"

void check(int number)
{
    for(int i = 1; i <= number; ++i)
    {
        for(int j = 1; j <= number; ++j)
        {
            gcd(i, j) == 1? printf("#") : printf(" ");
        }
        printf("\n");
    }
}

