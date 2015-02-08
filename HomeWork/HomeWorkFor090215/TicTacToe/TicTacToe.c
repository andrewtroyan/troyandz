#include <assert.h>
#define MAXROWS 4
#define MAXCOLS 4

void fillArrayWithEmptySymbols(char array[][MAXCOLS], int rows, int cols)
{
    assert(rows > 0 && rows <= MAXROWS && cols > 0 && cols <= MAXCOLS);
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++ j)
        {
            array[i][j] = ' ';
        }
    }
}

void showTable(char array[][MAXCOLS], int rows, int cols)
{
    assert(rows > 0 && rows <= MAXROWS && cols > 0 && cols <= MAXCOLS);
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

void fillTable(char array[][MAXCOLS])
{
    int row, column;
    char symbol;
    do
    {
        printf("Enter symbol, row and column to fill: ");
        scanf(" %c %d %d", &symbol, &row, &column);
        assert(row > 0 && row <= MAXROWS && column > 0 && column <= MAXCOLS);
        if(array[row - 1][column - 1] == 'X' || array[row - 1][column - 1] == 'O')
        {
            printf("You can't fill! Try again!\n");
        }
        else
        {
            array[row - 1][column - 1] = symbol;
            return 0;
        }
    }while(array[row - 1][column - 1] == 'X' || array[row - 1][column - 1] == 'O');
}


char checkFinish(char array[][MAXCOLS])
{
    char indicator = ' ';
    static int counter = 0;
    if(array[0][0] != ' ' && array[0][0] == array[0][1] && array[0][1] == array[0][2] && array[0][2] == array[0][3])
    {
        return array[0][0];
    }
    else if(array[1][0] != ' ' && array[1][0] == array[1][1] && array[1][1] == array[1][2] && array[1][2] == array[1][3])
    {
        return array[1][0];
    }
    else if(array[2][0] != ' ' && array[2][0] == array[2][1] && array[2][1] == array[2][2] && array[2][2] == array[2][3])
    {
        return array[2][0];
    }
    else if(array[3][0] != ' ' && array[3][0] == array[3][1] && array[3][1] == array[3][2] && array[3][2] == array[3][3])
    {
        return array[3][0];
    }
    else if(array[0][0] != ' ' && array[0][0] == array[1][0] && array[1][0] == array[2][0] && array[2][0] == array[3][0])
    {
        return array[0][0];
    }
    else if(array[0][1] != ' ' && array[0][1] == array[1][1] && array[1][1] == array[2][1] && array[2][1] == array[3][1])
    {
        return array[0][1];
    }
    else if(array[0][2] != ' ' && array[0][2] == array[1][2] && array[1][2] == array[2][2] && array[2][2] == array[3][2])
    {
        return array[0][2];
    }
    else if(array[0][3] != ' ' && array[0][3] == array[1][3] && array[1][3] == array[2][3] && array[2][3] == array[3][3])
    {
        return array[0][3];
    }
    else if(array[0][0] != ' ' && array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[2][2] == array[3][3])
    {
        return array[0][0];
    }
    else if(array[3][0] != ' ' && array[3][0] == array[2][1] && array[2][1] == array[1][2] && array[1][2] == array[0][3])
    {
        return array[3][0];
    }
    else if(++counter == 16)
    {
        return '0';
    }
    return indicator;
}

void playTheGame(char array[][MAXCOLS], int rows, int cols)
{
    assert(rows > 0 && rows <= MAXROWS && cols > 0 && cols <= MAXCOLS);
    char indicator;
    do
    {
        showTable(array, rows, cols);
        fillTable(array);
        universalClear();
        indicator = checkFinish(array);
    }while(indicator == ' ');
    showTable(array, rows, cols);
    if(indicator == 'X' || indicator == 'O')
    {
        printf("Player that played with '%c' symbol won!", indicator);
    }
    else if(indicator == '0')
    {
        printf("There's no winners!");
    }
}




