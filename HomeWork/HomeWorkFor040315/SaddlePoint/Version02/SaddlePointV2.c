int minInRow(const int **array, int rows, int cols)
{
    int numberOfCol = 0;
    for(int j = 1; j < cols; ++j)
        if(array[rows][j] < array[rows][numberOfCol])
            numberOfCol = j;
    return numberOfCol;
}

int maxInCol(const int **array, int rows, int cols)
{
    int numberOfRow = 0;
    for(int i = 1; i < rows; ++i)
        if(array[i][cols] > array[numberOfRow][cols])
            numberOfRow = i;
    return numberOfRow;
}
