#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/array.h"
#include "../../../ClassWork/Task280115/searchArray.h"
#include "../askForGenerateOrWriting.h"
#include "interchangeFirstPositiveAndLastNegative.h"
#include "../../../modules/include/compatibility.h"

int main()
{
    int *array = NULL, sizeOfPart;
    printf("Enter the size of array: ");
    scanf("%d", &sizeOfPart);
    array = (int *)malloc(sizeOfPart * sizeof(int));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    askForGenerateOrWriting(array, sizeOfPart);
    universalClear();
    printf("Your array:\n");
    outputArray(array, sizeOfPart);
    interchangeFirstPositiveAndLastNegative(array, sizeOfPart);
    free(array);
    array = NULL;
    return 0;
}
