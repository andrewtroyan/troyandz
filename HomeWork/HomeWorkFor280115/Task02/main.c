#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compatibility.h"
#include "../../../modules/include/array.h"
#include "arraySearch.h"
#define SIZE 10

int main()
{
    int a[SIZE];
    int number;
    printf("Hello! Fill in the array with %d or less elements.\n", SIZE);
    inputArray(a, SIZE);
    universalClear();
    printf("Your array: ");
    outputArrray(a, SIZE);
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("%d", arraySearch(number, a, SIZE));
    return 0;
}
