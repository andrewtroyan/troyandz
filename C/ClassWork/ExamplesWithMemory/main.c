#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array;
    array = (int *)malloc(20 * sizeof(int));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    return 0;
}
