#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE 199309L

#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

void treatSigWinch(int signo);
void initialiseProgram();
enum Colors {normal, green, red};
char closeCell[4] = "\342\227\206";
char flaggedCell[4] = "\342\227\204";

enum State {opened, hidden, flagged}; //состояния fogOfWar

#define ROWS 15
#define COLS 17

void initFields(int fogOfWar[][COLS], int field[][COLS], int rows, int cols);
void drawField(int fogOfWar[][COLS], int field[][COLS], int rows, int cols);

int main()
{
    initialiseProgram();
    int fogOfWar[ROWS][COLS];
    int field[ROWS][COLS]; //0 - empty, 1-8 - amount of bombs, 9 - bomb

    initFields(fogOfWar, field, ROWS, COLS);
    drawField(fogOfWar, field, ROWS, COLS);
    getch();
    endwin();
    return 0;
}

void initialiseProgram()
{
    setlocale(LC_ALL, "");
    initscr();
    signal(SIGWINCH, treatSigWinch);
    if(has_colors() == FALSE)
    {
        endwin();
        fprintf(stderr, "no colors\n");
        exit(1);
    }
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_pair(normal, COLOR_WHITE, COLOR_BLACK);
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);
}

void treatSigWinch(int signo)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);
}

void runAround(int filed[][COLS], int rows, int cols, int a, int b);

void inc(int field[][COLS], int rows, int cols, int i, int j);

void initFields(int fogOfWar[][COLS], int field[][COLS], int rows, int cols)
{
    int amountOfCells = rows * cols, amountOfBombs = 10;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            fogOfWar[i][j] = hidden;
            field[i][j] = 0;
        }
    }

    for(int i = 0; i < amountOfBombs; ++i)
    {
        int bombPosition = rand() % amountOfCells;
        int bombI = bombPosition / cols;
        int bombJ = bombPosition % cols;
        field[bombI][bombJ] = 9;
        runAround(field, rows, cols, bombI, bombJ);
    }
}

void runAround(int field[][COLS], int rows, int cols, int a, int b)
{
    for(int i = a -1; i < a + 2; ++i)
    {
        for(int j = b - 1; j < b + 2; ++j)
        {
            inc(field, rows, cols, i, j);
        }
    }
}

void inc(int field[][COLS], int rows, int cols, int i, int j)
{
    if(i >= 0 && j >= 0 && i < rows && j < cols && field[i][j] < 9)
    {
        ++field[i][j];
    }
}

void drawField(int fogOfWar[][COLS], int field[][COLS], int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            move(i, j);
            if(fogOfWar[i][j] == opened)
            {
                if(field[i][j] == 0)
                {
                    printw(" ");
                }
                else
                {
                    printw("%d", field[i][j]);
                }
            }
            else if(fogOfWar[i][j] == hidden)
            {
                printw("%s", closeCell);
            }
            else if(fogOfWar[i][j] == flagged)
            {
                printw("%s", flaggedCell);
            }
            else
            {
                endwin();
                fprintf(stderr, "Internal error: \nImpossible value for fog.\n");
                exit(1);
            }
        }
    }
}


