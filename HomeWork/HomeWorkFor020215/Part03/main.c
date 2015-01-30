#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/array.h"
#include "../../../modules/include/compatibility.h"
#include "../askForGenerateOrWriting.h"

int main()
{
    int array[SIZE], sizeOfPart;
    printf("Enter the size of array (0 < size <= %d): ", SIZE);
    scanf("%d", &sizeOfPart);
    askForGenerateOrWriting(array, sizeOfPart);
    universalClear();
    printf("Your array:\n");
    outputArrray(array, sizeOfPart);

    return 0;
}
