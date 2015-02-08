#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compatibility.h"
#include "tictactoe.h"

int main()
{
    char table[MAXROWS][MAXCOLS];
    fillArrayWithEmptySymbols(table, 4, 4);
    printf("Welcome to Tic-Tac-Toe game!");
    universalSleep(2.0);
    universalClear();
    playTheGame(table, 4, 4);
    return 0;
}
