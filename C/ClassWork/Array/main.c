#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/array.h"

int main()
{
    int *array = NULL, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    printf("Enter array of %d elements:\n", size);
    inputArray(array, size);
    outputArray(array, size);
    free(array);
    array = NULL;
    return 0;
}


