#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("ASCII symbols for codes in [0; 127]:\n");
    for (int number = 0, i = 1; number <= 127; ++number, ++i)
    {
        if (i%16 != 0)
        {
            printf("%c ", number);
        }
        else
        {
            printf("%c\n", number);
        }
    }
    return 0;
}
