#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/array.h"
#define N 1000

int main()
{
    int a[N];
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array of %d elements:\n", n);
    input(a, n);
    output(a, n);
    return 0;
}


