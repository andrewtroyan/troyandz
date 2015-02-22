#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe3D.h"

int main()
{
    int field[4][4][4] = {0}, resultOfGame = 0;

    initialiseProgram();
    attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
    printw("Welcome to Tic Tac Toe 3D!");
    attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
    getch();
    clear();

    while(resultOfGame == 0)
    {
        playTheGame(field, 4, 4, 4);
        resultOfGame = checkTheGame(field, 4, 4, 4);
    }
    switch(resultOfGame)
    {
    case 1:
        drawField(field, 4, 4, 4);
        attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        printw("\nThe player with \"O\" symbols won!\n");
        attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        break;
    case 2:
        drawField(field, 4, 4, 4);
        attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        printw("\nThe player with \"X\" symbols won!\n");
        attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        break;
    case 3:
        drawField(field, 4, 4, 4);
        attron(COLOR_PAIR(red)|A_BOLD|A_BLINK);
        printw("\nThere's no empty cells!\n");
        attroff(COLOR_PAIR(red)|A_BOLD|A_BLINK);
        break;
    }
    getch();
    return 0;
}
