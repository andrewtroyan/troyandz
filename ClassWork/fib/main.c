#include <stdio.h>
#include <stdlib.h>

int fb(int n);

int main()
{
    printf("%d", fb(30));
    return 0;
}

int fb(int n)
{
    if(n == 1 || n == 2)
        return 1;
    else
        return fb(n - 1) + fb(n - 2);
}

//в данном случае рекурсия неприменима
