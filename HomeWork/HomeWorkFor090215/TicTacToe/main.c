#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compatibility.h"
#include "TicTacToe.h"

int main()
{
    char **table = NULL;
    table = (char **)malloc(4 * sizeof(char *));
    if(table == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    for(int i = 0; i < 4; ++i)
    {
        table[i] = NULL;
        table[i] = (char *)malloc(4 * sizeof(char *));
        if(table[i] == NULL)
        {
            for(int index = i; index > 0; --index)
            {
                free(table[index - 1]);
                table[index - 1] = NULL;
            }
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
    }

    fillArrayWithEmptySymbols(table);
    printf("Welcome to Tic-Tac-Toe game!");
    universalSleep(2.0);
    universalClear();
    playTheGame(table);

    for(int i = 0; i < 4; ++i)
    {
        free(table[i]);
        table[i] = NULL;
    }
    free(table);
    table = NULL;
    return 0;
}
