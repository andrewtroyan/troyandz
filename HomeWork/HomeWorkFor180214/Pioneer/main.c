#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE 199309L

#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

void treatSigWinch(int signo);
void initialiseProgram();
enum Colors {normal, green, red};
char closeCell[4] = "\342\227\206";
char flaggedCell[4] = "\342\227\204";
static int upDown = 0, leftRight = 0;

enum State {opened, hidden, flagged}; //состояния fogOfWar

#define ROWS 15
#define COLS 17

void initFields(int fogOfWar[][COLS], int field[][COLS], int rows, int cols);
void drawField(int fogOfWar[][COLS], int field[][COLS], int rows, int cols, int cellI, int cellJ);
int playTheGame(int fogOfWar[][COLS], int field[][COLS], int rows, int cols, int cellI, int cellJ);

int main()
{
    initialiseProgram();
    int fogOfWar[ROWS][COLS];
    int field[ROWS][COLS]; //0 - empty, 1-8 - amount of bombs, 9 - bomb
    bool game = true;
    int resultOfGame = 0;
    char symbol;

    initFields(fogOfWar, field, ROWS, COLS);

    while(game == true)
    {
        resultOfGame = playTheGame(fogOfWar, field, ROWS, COLS, upDown, leftRight);
        switch(resultOfGame)
        {
        case 1:
            drawField(fogOfWar, field, ROWS, COLS, upDown, leftRight);
            attron(COLOR_PAIR(red)|A_BOLD|A_BLINK);
            printw("\nYou lose!\n");
            attron(COLOR_PAIR(red)|A_BOLD|A_BLINK);
            game = false;
            break;
        case 2:
            drawField(fogOfWar, field, ROWS, COLS, upDown, leftRight);
            attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
            printw("\nYou won!\n");
            attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
            game = false;
            break;
        }
    }
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

int amountOfBombs = 10;

void initFields(int fogOfWar[][COLS], int field[][COLS], int rows, int cols)
{
    int amountOfCells = rows * cols;
    srand(time(NULL));

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

void drawField(int fogOfWar[][COLS], int field[][COLS], int rows, int cols, int cellI, int cellJ)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            move(i, j);
            if(cellI == i && cellJ == j)
            {
                attron(A_REVERSE);
            }
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
            if(cellI == i && cellJ == j)
            {
                attroff(A_REVERSE);
            }
        }
    }
    refresh();
}

void openRecursively(int fogOfWar[][COLS], int field[][COLS], int rows, int cols, int cellI, int cellJ);
static int indicatorOfOpenedCells = 0;

int playTheGame(int fogOfWar[][COLS], int field[][COLS], int rows, int cols, int cellI, int cellJ)
{
    drawField(fogOfWar, field, rows, cols, cellI, cellJ);
    char symbol = getch();
    static int indicatorOfFlags = 0, amountOfOpenCells;
    amountOfOpenCells = rows * cols - amountOfBombs;
    switch(symbol)
    {
    case 'w':
        if(upDown == 0 && leftRight == 0)
        {
            upDown = rows - 1;
            leftRight = cols - 1;
        }
        else if(upDown == 0)
        {
            upDown = rows - 1;
            --leftRight;
        }
        else
        {
            --upDown;
        }
        break;
    case 's':
        if(upDown == rows - 1 && leftRight == cols - 1)
        {
            upDown = 0;
            leftRight = 0;
        }
        else if(upDown == rows - 1)
        {
            upDown = 0;
            ++leftRight;
        }
        else
        {
            ++upDown;
        }
        break;
    case 'a':
        if(upDown == 0 && leftRight == 0)
        {
            upDown = rows - 1;
            leftRight = cols - 1;
        }
        else if(leftRight == 0)
        {
            --upDown;
            leftRight = cols - 1;
        }
        else
        {
            --leftRight;
        }
        break;
    case 'd':
        if(upDown == rows - 1 && leftRight == cols - 1)
        {
            upDown = 0;
            leftRight = 0;
        }
        else if(leftRight == cols - 1)
        {
            ++upDown;
            leftRight = 0;
        }
        else
        {
            ++leftRight;
        }
        break;
    case 'f':
        if(fogOfWar[cellI][cellJ] == hidden)
        {
            if(indicatorOfFlags < amountOfBombs)
            {
                fogOfWar[cellI][cellJ] = flagged;
                ++indicatorOfFlags;
            }
        }
        else if(fogOfWar[cellI][cellJ] == flagged)
        {
            fogOfWar[cellI][cellJ] = hidden;
            --indicatorOfFlags;
        }
        break;
    case ' ':
        if(fogOfWar[cellI][cellJ] == hidden)
        {
            if(field[cellI][cellJ] == 9)
            {
                fogOfWar[cellI][cellJ] = opened;
                return 1;
            }
            else if(field[cellI][cellJ] > 0 && field[cellI][cellJ] < 9)
            {
                fogOfWar[cellI][cellJ] = opened;
                ++indicatorOfOpenedCells;
            }
            else if(field[cellI][cellJ] == 0)
            {
                openRecursively(fogOfWar, field, ROWS, COLS, cellI, cellJ);
                //fogOfWar[cellI][cellJ] = opened;
                //++indicatorOfOpenedCells;
            }
            else if(indicatorOfOpenedCells == amountOfOpenCells)
            {
                return 2;
            }
        }
        break;
    }
    return 0;
}


void openRecursively(int fogOfWar[][COLS], int field[][COLS], int rows, int cols, int cellI, int cellJ)
{
    if(field[cellI][cellJ] == 0)
    {
        fogOfWar[cellI][cellJ] = opened;
        for(int i = cellI - 1; i < cellI + 2; ++i)
        {
            for(int j = cellI - 1; j < cellJ + 2; ++j)
            {
                if(i >= 0 && j >= 0 && i < rows && j < cols)
                {
                    openRecursively(fogOfWar, field, ROWS, COLS, i, j);
                }
            }
        }
        ++indicatorOfOpenedCells;
    }
    else if(field[cellI][cellJ] != 0)
    {
        return 0;
    }
}
