#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("ASCII symbols for codes in [0; 127]:\n");
    for (int number = 1; number <= 128; ++number)
    {
        if (number%16 != 0)
        {
            printf("%c ", number - 1);
        }
        else
        {
            printf("%c\n", number - 1);
        }
    }
    return 0;
}
