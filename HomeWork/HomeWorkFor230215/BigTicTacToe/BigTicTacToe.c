#include "BigTicTacToe.h"

static char unusedCell[4] = "\342\227\206";
static int upDown = 0, leftRight = 0;

void treatSigWinch(int signo)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);
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

void drawField(int field[][20], int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            move(i, j);
            if(upDown == i && leftRight == j)
            {
                attron(A_REVERSE);
            }
            if(field[i][j] == 0)
            {
                printw("%s", unusedCell);
            }
            else if(field[i][j] == 1)
            {
                attron(COLOR_PAIR(yellow)|A_BOLD);
                printw("O");
                attroff(COLOR_PAIR(yellow)|A_BOLD);
            }
            else if(field[i][j] == 2)
            {
                attron(COLOR_PAIR(blue)|A_BOLD);
                printw("X");
                attroff(COLOR_PAIR(blue)|A_BOLD);
            }
            else
            {
                endwin();
                fprintf(stderr, "Internal error: \nImpossible value for field.\n");
                exit(1);
            }
            if(upDown == i && leftRight == j)
            {
                attroff(A_REVERSE);
            }
        }
    }
    refresh();
}

void playTheGame(int field[][20], int rows, int cols)
{
    drawField(field, rows, cols);
    keypad(stdscr, true);
    int symbol = getch();
    switch(symbol)
    {
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
    case 111:
        if(field[upDown][leftRight] == 0)
        {
            field[upDown][leftRight] = 1;
        }
        break;
    case 120:
        if(field[upDown][leftRight] == 0)
        {
            field[upDown][leftRight] = 2;
        }
        break;
    }
    return 0;
}

int checkHorizontal(int field[][20], int rows, int cols)
{
    int indicator = 0;
    for(int k = leftRight; k > 0 && field[upDown][k] == field[upDown][k - 1]; --k)
    {
        ++indicator;
    }
    for(int k = leftRight; k < cols - 1 && field[upDown][k] == field[upDown][k + 1]; ++k)
    {
        ++indicator;
    }
    if(indicator == 4)
    {
        if(field[upDown][leftRight] == 1)
        {
            return 1;
        }
        else if(field[upDown][leftRight] == 2)
        {
            return 2;
        }
    }
    return 0;
}

int checkVertical(int field[][20], int rows, int cols)
{
    int indicator = 0;
    for(int k = upDown; k > 0 && field[k][leftRight] == field[k - 1][leftRight]; --k)
    {
        ++indicator;
    }
    for(int k = upDown; k < rows - 1 && field[k][leftRight] == field[k + 1][leftRight]; ++k)
    {
        ++indicator;
    }
    if(indicator == 4)
    {
        if(field[upDown][leftRight] == 1)
        {
            return 1;
        }
        else if(field[upDown][leftRight] == 2)
        {
            return 2;
        }
    }
    return 0;
}

int checkLeftDiagonal(int field[][20], int rows, int cols)
{
    int indicator = 0;
    for(int k = upDown, l = leftRight; k > 0 && l > 0 && field[k][l] == field[k - 1][l - 1]; --k, --l)
    {
        ++indicator;
    }
    for(int k = upDown, l = leftRight; k < rows - 1 && l < cols - 1 && field[k][l] == field[k + 1][l + 1]; ++k, ++l)
    {
        ++indicator;
    }
    if(indicator == 4)
    {
        if(field[upDown][leftRight] == 1)
        {
            return 1;
        }
        else if(field[upDown][leftRight] == 2)
        {
            return 2;
        }
    }
    return 0;
}

int checkRightDiagonal(int field[][20], int rows, int cols)
{
    int indicator = 0;
    for(int k = upDown, l = leftRight; k < rows - 1 && l > 0 && field[k][l] == field[k + 1][l - 1]; ++k, --l)
    {
        ++indicator;
    }
    for(int k = upDown, l = leftRight; k > 0 && l < cols - 1 && field[k][l] == field[k - 1][l + 1]; --k, ++l)
    {
        ++indicator;
    }
    if(indicator == 4)
    {
        if(field[upDown][leftRight] == 1)
        {
            return 1;
        }
        else if(field[upDown][leftRight] == 2)
        {
            return 2;
        }
    }
    return 0;
}

int checkTheGame(int field[][20], int rows, int cols)
{
    int amountOfUnusedCells = 0, a = checkVertical(field, 20, 20), b = checkHorizontal(field, 20, 20), c = checkLeftDiagonal(field, 20, 20), d = checkRightDiagonal(field, 20, 20);
    if(a != 0 || b != 0 || c != 0 || d !=  0)
    {
        if(a != 0)
        {
            return a;
        }
        else if(b != 0)
        {
            return b;
        }
        else if(c != 0)
        {
            return c;
        }
        else if(d != 0)
        {
            return d;
        }
    }
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(field[i][j] == 0)
            {
                ++amountOfUnusedCells;
            }
        }
    }
    if(amountOfUnusedCells == 0)
    {
        return 3;
    }
    return 0;
}
