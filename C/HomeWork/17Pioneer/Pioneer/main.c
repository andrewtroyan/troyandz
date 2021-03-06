#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/ncursesDetails.h"

char closeCell[4] = "\342\227\206";
static int upDown = 0, leftRight = 0, rowsOfField, colsOfField, amountOfBombs;

enum State {opened, hidden, flagged}; //состояния fogOfWar

void initFields(int **fogOfWar, int **field, int rows, int cols);
void drawField(int **fogOfWar, int **field, int rows, int cols, int cellI, int cellJ);
void playTheGame(int **fogOfWar, int **field, int rows, int cols);
int checkTheStep(int **fogOfWar, int **field, int rows, int cols);

int main()
{
    int resultOfGame = 0, **fogOfWar = NULL, **field = NULL; //для field: 0 - empty, 1-8 - amount of bombs, 9 - bomb
    system("clear");
    printf("Enter the amount of rows: ");
    scanf("%d", &rowsOfField);

    fogOfWar = (int **)malloc(rowsOfField * sizeof(int *));
    field = (int **)malloc(rowsOfField * sizeof(int *));

    if(fogOfWar == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    else if(field == NULL)
    {
        free(fogOfWar);
        fogOfWar = NULL;
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    printf("Enter the amount of cols: ");
    scanf("%d", &colsOfField);

    for(int i = 0; i < rowsOfField; ++i)
    {
        fogOfWar[i] = (int *)malloc(colsOfField * sizeof(int));
        field[i] = (int *)malloc(colsOfField * sizeof(int));
        if(fogOfWar[i] == NULL || field[i] == NULL)
        {
            for(int index = i; index >= 0; --index)
            {
                free(fogOfWar[index]);
                free(field[index]);
                fogOfWar[index] = NULL;
                field[index] = NULL;
            }
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
    }

    printf("Enter the amount of bombs (less or equal %d): ", rowsOfField * (colsOfField * 40 / 100));
    scanf("%d", &amountOfBombs);
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

    for(int i = 0; i < rowsOfField; ++i)
    {
        free(fogOfWar[i]);
        free(field[i]);
        fogOfWar[i] = NULL;
        field[i] = NULL;
    }

    free(fogOfWar);
    free(field);
    fogOfWar = NULL;
    field = NULL;

    getch();
    endwin();

    return 0;
}

void runAround(int **field, int rows, int cols, int a, int b);

void inc(int **field, int rows, int cols, int i, int j);

void initFields(int **fogOfWar, int **field, int rows, int cols)
{
    int amountOfCells = rows * cols;
    srand(time(NULL));

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            fogOfWar[i][j] = hidden;
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

void runAround(int **field, int rows, int cols, int a, int b)
{
    for(int i = a - 1; i < a + 2; ++i)
    {
        for(int j = b - 1; j < b + 2; ++j)
        {
            inc(field, rows, cols, i, j);
        }
    }
}

void inc(int **field, int rows, int cols, int i, int j)
{
    if(i >= 0 && j >= 0 && i < rows && j < cols && field[i][j] < 9)
    {
        ++field[i][j];
    }
}

void drawField(int **fogOfWar, int **field, int rows, int cols, int cellI, int cellJ)
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

void openRecursively(int **fogOfWar, int **field, int rows, int cols, int cellI, int cellJ);

void playTheGame(int **fogOfWar, int **field, int rows, int cols)
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
}


void openRecursively(int **fogOfWar, int **field, int rows, int cols, int cellI, int cellJ)
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

int checkTheStep(int **fogOfWar, int **field, int rows, int cols)
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
