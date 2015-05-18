#include <stdio.h>
#include <stdlib.h>
#include "check.h"

int main()
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    check(number);
    return 0;
}
