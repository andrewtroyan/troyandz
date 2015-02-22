#include <stdio.h>
#include <stdlib.h>
#include "BigTicTacToe.h"

int main()
{
    int field[20][20] = {0}, resultOfGame = 0;

    initialiseProgram();
    attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
    printw("Welcome to big Tic Tac Toe!");
    attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
    getch();
    clear();

    while(resultOfGame == 0)
    {
        playTheGame(field, 20, 20);
        resultOfGame = checkTheGame(field, 20, 20);
    }
    switch(resultOfGame)
    {
    case 1:
        drawField(field, 20, 20);
        attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        printw("\nThe player with \"O\" symbols won!\n");
        attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        break;
    case 2:
        drawField(field, 20, 20);
        attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        printw("\nThe player with \"X\" symbols won!\n");
        attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
        break;
    case 3:
        drawField(field, 20, 20);
        attron(COLOR_PAIR(red)|A_BOLD|A_BLINK);
        printw("\nThere's no empty cells!\n");
        attroff(COLOR_PAIR(red)|A_BOLD|A_BLINK);
        break;
    }
    getch();
    return 0;
}
