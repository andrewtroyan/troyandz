#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int **array = NULL, rows, cols;
    srand(time(NULL));
    printf("Enter the amount of rows: ");
    scanf("%d", &rows);
    array = (int **)malloc(rows * sizeof(int *));
    if(array == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    printf("Enter the amount of cols: ");
    scanf("%d", &cols);
    for(int i = 0; i < rows; ++i)
    {
        array[i] = NULL;
        array[i] = (int *)malloc(cols * sizeof(int));
        if(array[i] == NULL)
        {
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
    }
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            array[i][j] = rand() % 10;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < rows; ++i)
    {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
    return 0;
}
