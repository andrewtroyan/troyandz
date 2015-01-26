#include <stdio.h>
#include <stdlib.h>
#include "combinate.h"

int main()
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    permute(number);
    return 0;
}


