int maxInCol(const int **array, int rows, int cols)
{
    int numberOfRow = 0;
    for(int i = 1; i < rows; ++i)
        if(array[i][cols] > array[numberOfRow][cols])
            numberOfRow = i;
    return numberOfRow;
}
