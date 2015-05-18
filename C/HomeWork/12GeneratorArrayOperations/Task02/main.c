#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compatibility.h"
#include "../../../modules/include/array.h"
#define SIZE 10

int main()
{
    int array[SIZE];
    int number;
    printf("Hello! Fill in the array with %d elements.\n", SIZE);
    inputArray(array, SIZE);
    universalClear();
    printf("Your array: ");
    outputArrray(array, SIZE);
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("%d", arraySearch(number, array, SIZE));
    return 0;
}
