#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i=1; i<=100; ++i)
    {
        for (int k=0; k<100; ++k)
        {
            printf(">---- %d%%\r", i);
        }
        for (int k=0; k<100; ++k)
        {
            printf("->--- %d%%\r", i);
        }
        for (int k=0; k<100; ++k)
        {
            printf("-->-- %d%%\r", i);
        }
        for (int k=0; k<100; ++k)
        {
            printf("--->- %d%%\r", i);
        }
        for (int k=0; k<100; ++k)
        {
            printf("----> %d%%\r", i);
        }
    }
    return 0;
}
