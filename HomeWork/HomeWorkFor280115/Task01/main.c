#include <stdio.h>
#include <stdlib.h>
#include "myRandom.h"

int main()
{
    printf("The random number according Wikipedia coefficients: %d.\n", random());
    printf("The random number according my own coefficients: %d.\n", myRandom());
    return 0;
}



