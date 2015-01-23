#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compatibility.h"
#include "animation.h"

int main()
{
    int sizeOfSquare;
    printf("Enter the size of square: ");
    scanf("%d", &sizeOfSquare);
    animation(sizeOfSquare);
    return 0;
}
