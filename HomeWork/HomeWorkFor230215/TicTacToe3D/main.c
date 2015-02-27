#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe3D.h"

int main()
{
    int ***field = NULL, resultOfGame = 0;

    field = (int ***)malloc(LAYERS * sizeof(int **));
    if(field == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    for(int i = 0; i < LAYERS; ++i)
    {
        field[i] = NULL;
        field[i] = (int **)malloc(ROWS * sizeof(int *));
        if(field[i] == NULL)
        {
            for(int index = i; index > 0; --index)
            {
                free(field[index - 1]);
                field[index - 1] = NULL;
            }
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
        for(int j = 0; j < ROWS; ++j)
        {
            field[i][j] = NULL;
            field[i][j] = (int *)malloc(COLS * sizeof(int));
            if(field[i][j] == NULL)
            {
                for(int indexI = i; indexI >= 0; --indexI)
                {
                    for(int indexJ = j; indexJ >= 0; --indexJ)
                    {
                        free(field[indexI][indexJ]);
                        field[indexI][indexJ] = NULL;
                    }
                }
                fprintf(stderr, "No free memory.\n");
                exit(1);
            }
        }
    }

    initialiseProgram();
    attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
    printw("Welcome to Tic Tac Toe 3D!");
    attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
    getch();
    clear();

    while(resultOfGame == 0)
    {
        playTheGame(field);
        resultOfGame = checkTheGame(field);
    }
    switch(resultOfGame)
    {
    case 1:
        drawField(field);
        attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        printw("\nThe player with \"O\" symbols won!\n");
        attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        break;
    case 2:
        drawField(field);
        attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        printw("\nThe player with \"X\" symbols won!\n");
        attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        break;
    case 3:
        drawField(field);
        attron(COLOR_PAIR(red)|A_BOLD|A_BLINK);
        printw("\nThere's no empty cells!\n");
        attroff(COLOR_PAIR(red)|A_BOLD|A_BLINK);
        break;
    }

    for(int i = 0; i < LAYERS; ++i)
    {
        for(int j = 0; j < ROWS; ++j)
        {
            free(field[i][j]);
            field[i][j] = NULL;
        }
        free(field[i]);
        field[i] = NULL;
    }

    free(field);
    field = NULL;

    getch();
    return 0;
}
