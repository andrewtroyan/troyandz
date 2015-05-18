#include "QsortDetails.h"

int main()
{
    int *array = NULL, size;
    printf("Enter the size: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    generateRandomNumbersInArray(array, size, 0, 15);
    printf("Your array:\n");
    outputArray(array, size);
    qsort(array, size, sizeof(int), functionForQsort);
    printf("Your sorted array:\n");
    outputArray(array, size);
    free(array);
    array = NULL;
    return 0;
}

