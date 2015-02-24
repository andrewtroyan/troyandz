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

#define ROWS 30
#define COLS 50

void treatSigWinch(int signo);
void initialiseProgram();
enum Colors {normal, green, red, blue, yellow};
char closeCell[4] = "\342\227\206";
static int upDown = 0, leftRight = 0, rowsOfField, colsOfField, amountOfBombs;

enum State {opened, hidden, flagged}; //состояния fogOfWar

void initFields(int fogOfWar[][COLS], int field[][COLS], int rows, int cols);
void drawField(int fogOfWar[][COLS], int field[][COLS], int rows, int cols, int cellI, int cellJ);
void playTheGame(int fogOfWar[][COLS], int field[][COLS], int rows, int cols);
int checkTheStep(int fogOfWar[][COLS], int field[][COLS], int rows, int cols);

int main()
{
    int fogOfWar[ROWS][COLS];
    int field[ROWS][COLS]; //0 - empty, 1-8 - amount of bombs, 9 - bomb
    int resultOfGame = 0;
    do
    {
        system("clear");
        printf("Enter the amount of rows (less or equal %d): ", ROWS);
        scanf("%d", &rowsOfField);
        printf("Enter the amount of cols (less or equal %d): ", COLS);
        scanf("%d", &colsOfField);
        printf("Enter the amount of bombs (less or equal %d): ", rowsOfField * (colsOfField * 40 / 100));
        scanf("%d", &amountOfBombs);
        if(rowsOfField > 0 && rowsOfField <= ROWS && colsOfField > 0 && colsOfField <= COLS && amountOfBombs > 0 && amountOfBombs <= rowsOfField * (colsOfField * 40 / 100))
        {
            system("clear");

            initialiseProgram();

            initFields(fogOfWar, field, rowsOfField, colsOfField);

            while(resultOfGame == 0)
            {
                playTheGame(fogOfWar, field, rowsOfField, colsOfField);
                resultOfGame = checkTheStep(fogOfWar, field, rowsOfField, colsOfField);
            }
            switch(resultOfGame)
            {
            case 1:
                for(int i = 0; i < rowsOfField; ++i)
                {
                    for(int j = 0; j < colsOfField; ++j)
                    {
                        if(field[i][j] == 9)
                        {
                            fogOfWar[i][j] = opened;
                        }
                    }
                }
                drawField(fogOfWar, field, rowsOfField, colsOfField, upDown, leftRight);
                attron(COLOR_PAIR(red)|A_BOLD|A_BLINK);
                printw("\nYou lose!\n");
                attroff(COLOR_PAIR(red)|A_BOLD|A_BLINK);
                break;
            case 2:
                drawField(fogOfWar, field, rowsOfField, colsOfField, upDown, leftRight);
                attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
                printw("\nYou won!\n");
                attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
                break;
            }
        }
    }
    while(rowsOfField <= 0 || rowsOfField > ROWS || colsOfField <= 0 || colsOfField > COLS || amountOfBombs <= 0 || amountOfBombs > rowsOfField * (colsOfField * 40 / 100));
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
    init_pair(blue, COLOR_BLUE, COLOR_BLACK);
    init_pair(yellow, COLOR_YELLOW, COLOR_BLACK);
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
        int bombI, bombJ;
        do
        {
            int bombPosition = rand() % amountOfCells;
            bombI = bombPosition / cols;
            bombJ = bombPosition % cols;
        }
        while(field[bombI][bombJ] == 9);
        field[bombI][bombJ] = 9;
        runAround(field, rows, cols, bombI, bombJ);
    }
}

void runAround(int field[][COLS], int rows, int cols, int a, int b)
{
    for(int i = a - 1; i < a + 2; ++i)
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
                else if(field[i][j] > 0 && field[i][j] < 9)
                {
                    attron(COLOR_PAIR(blue)|A_BOLD);
                    printw("%d", field[i][j]);
                    attroff(COLOR_PAIR(blue)|A_BOLD);
                }
                else if(field[i][j] == 9)
                {
                    attron(COLOR_PAIR(red)|A_BOLD);
                    printw("*");
                    attroff(COLOR_PAIR(red)|A_BOLD);
                }
            }
            else if(fogOfWar[i][j] == hidden)
            {
                printw("%s", closeCell);
            }
            else if(fogOfWar[i][j] == flagged)
            {
                attron(COLOR_PAIR(yellow)|A_BOLD);
                printw("?");
                attroff(COLOR_PAIR(yellow)|A_BOLD);
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

void playTheGame(int fogOfWar[][COLS], int field[][COLS], int rows, int cols)
{
    drawField(fogOfWar, field, rows, cols, upDown, leftRight);
    keypad(stdscr, true);
    MEVENT event;
    mousemask(ALL_MOUSE_EVENTS, NULL);
    int symbol = wgetch(stdscr);
    static int indicatorOfFlags = 0;
    switch(symbol)
    {
    case KEY_MOUSE:
        getmouse(&event);
        upDown = event.y, leftRight = event.x;
        if(event.bstate & BUTTON1_CLICKED || event.bstate & BUTTON1_DOUBLE_CLICKED || event.bstate & BUTTON1_PRESSED || event.bstate & BUTTON1_RELEASED || event.bstate & BUTTON1_RESERVED_EVENT || event.bstate & BUTTON1_TRIPLE_CLICKED)
        {
            if(field[upDown][leftRight] == 0 && fogOfWar[upDown][leftRight] == hidden)
            {
                openRecursively(fogOfWar, field, rows, cols, upDown, leftRight);
            }
            else if(fogOfWar[upDown][leftRight] == hidden)
            {
                fogOfWar[upDown][leftRight] = opened;
            }
        }
        else
        {
            if(fogOfWar[upDown][leftRight] == hidden)
            {
                if(indicatorOfFlags < amountOfBombs)
                {
                    fogOfWar[upDown][leftRight] = flagged;
                    ++indicatorOfFlags;
                }
            }
            else if(fogOfWar[upDown][leftRight] == flagged)
            {
                fogOfWar[upDown][leftRight] = hidden;
                --indicatorOfFlags;
            }
        }
        break;
    case KEY_UP:
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
    case KEY_DOWN:
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
    case KEY_LEFT:
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
    case KEY_RIGHT:
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
    case 102:
        if(fogOfWar[upDown][leftRight] == hidden)
        {
            if(indicatorOfFlags < amountOfBombs)
            {
                fogOfWar[upDown][leftRight] = flagged;
                ++indicatorOfFlags;
            }
        }
        else if(fogOfWar[upDown][leftRight] == flagged)
        {
            fogOfWar[upDown][leftRight] = hidden;
            --indicatorOfFlags;
        }
        break;
    case 32:
        if(field[upDown][leftRight] == 0 && fogOfWar[upDown][leftRight] == hidden)
        {
            openRecursively(fogOfWar, field, rows, cols, upDown, leftRight);
        }
        else if(fogOfWar[upDown][leftRight] == hidden)
        {
            fogOfWar[upDown][leftRight] = opened;
        }
        break;
    }
    return 0;
}


void openRecursively(int fogOfWar[][COLS], int field[][COLS], int rows, int cols, int cellI, int cellJ)
{
    if(cellI >= 0 && cellJ >= 0 && cellI < rows && cellJ < cols )
    {
        if(fogOfWar[cellI][cellJ] == hidden)
        {
            fogOfWar[cellI][cellJ] = opened;

            if(field[cellI][cellJ] == 0)
            {
                openRecursively(fogOfWar, field, rows, cols, cellI - 1, cellJ);
                openRecursively(fogOfWar, field, rows, cols, cellI + 1, cellJ);
                openRecursively(fogOfWar, field, rows, cols, cellI, cellJ - 1);
                openRecursively(fogOfWar, field, rows, cols, cellI, cellJ + 1);
            }
        }
    }
}

int checkTheStep(int fogOfWar[][COLS], int field[][COLS], int rows, int cols)
{
    int amountOfClosedCells = 0;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(field[i][j] == 9 && fogOfWar[i][j] == opened)
            {
                return 1;
            }
            else if(fogOfWar[i][j] == hidden || fogOfWar[i][j] == flagged)
            {
                ++amountOfClosedCells;
            }
        }
    }
    if(amountOfClosedCells == amountOfBombs)
    {
        return 2;
    }
    return 0;
}
