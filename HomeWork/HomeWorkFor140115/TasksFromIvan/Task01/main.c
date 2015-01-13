#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomLetter();

int main()
{
    srand(time(NULL));
    for(int i = 1; i <= 10; ++i)
    {
        randomLetter();
    }
    return 0;
}

void randomLetter()
{
    printf ("%c\n", rand() % 26 + 65);
}
