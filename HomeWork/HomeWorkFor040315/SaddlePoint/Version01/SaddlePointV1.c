void outputMatrix(int *array, int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            printf("%02d ", array[i * cols + j]);
        }
        printf("\n");
    }
}

int minInRow(int *array, int rows, int cols)
{
    int indexOfMin = 0;
    for(int i = 1; i < cols; ++i)
        if(array[rows * cols + i] < array[rows * cols + indexOfMin])
            indexOfMin = i;
    return indexOfMin;
}

int maxInCol(int *array, int rows, int cols, int currentColumn)
{
    int indexOfMax = 0;
    for(int i = 1; i < rows; ++i)
        if(array[i * cols + currentColumn] > array[indexOfMax * cols + currentColumn])
            indexOfMax = i;
    return indexOfMax;
}
