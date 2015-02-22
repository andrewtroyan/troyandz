#include "TicTacToe3D.h"
#include <stdbool.h>

static char unusedCell[4] = "\342\227\206";
static int currentLayer = 0, currentI = 0, currentJ = 0, upDown = 0, leftRight = 0;

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

void drawField(int field[][4][4], int layers, int rows, int cols)
{
    int up = 0, down = 0;
    for(int i = 0; i < layers; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            for(int k = 0; k < cols; ++k)
            {
                if(i == 0)
                {
                    up = j, down = k;
                }
                else if(i == 1)
                {
                    up = j, down = k + 5;
                }
                else if(i == 2)
                {
                    up = j + 5, down = k;
                }
                else if(i == 3)
                {
                    up = j + 5, down = k + 5;
                }
                move(up, down);
                if(currentLayer == i && upDown == up && leftRight == down)
                {
                    attron(A_REVERSE);
                }

                if(field[i][j][k] == 0)
                {
                    printw("%s", unusedCell);
                }
                else if(field[i][j][k] == 1)
                {
                    attron(COLOR_PAIR(yellow)|A_BOLD);
                    printw("O");
                    attroff(COLOR_PAIR(yellow)|A_BOLD);
                }
                else if(field[i][j][k] == 2)
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

                if(currentLayer == i && upDown == up && leftRight == down)
                {
                    attroff(A_REVERSE);
                }
            }
        }
    }
    refresh();
}

void playTheGame(int field[][4][4], int layers, int rows, int cols)
{
    drawField(field, layers, rows, cols);
    keypad(stdscr, true);
    int symbol = getch();
    switch(symbol)
    {
    case 49:
        currentLayer = 0;
        upDown = 0, leftRight = 0;
        break;
    case 50:
        currentLayer = 1;
        upDown = 0, leftRight = 5;
        break;
    case 51:
        currentLayer = 2;
        upDown = 5, leftRight = 0;
        break;
    case 52:
        currentLayer = 3;
        upDown = 5; leftRight = 5;
        break;
    case KEY_UP:
        if(upDown == 0 && currentLayer == 0)
        {
            upDown = rows + 4;
            currentLayer = 2;
        }
        else if(upDown == 0 && currentLayer == 1)
        {
            upDown = rows + 4;
            currentLayer = 3;
        }
        else if(upDown == 5 && currentLayer == 2)
        {
            upDown -= 2;
            currentLayer = 0;
        }
        else if(upDown == 5 && currentLayer == 3)
        {
            upDown -= 2;
            currentLayer = 1;
        }
        else
        {
            --upDown;
        }
        break;
    case KEY_DOWN:
        if(upDown == rows + 4 && currentLayer == 2)
        {
            upDown = 0;
            currentLayer = 0;
        }
        else if(upDown == rows + 4 && currentLayer == 3)
        {
            upDown = 0;
            currentLayer = 1;
        }
        else if(upDown == 3 && currentLayer == 0)
        {
            upDown += 2;
            currentLayer = 2;
        }
        else if(upDown == 3 && currentLayer == 1)
        {
            upDown += 2;
            currentLayer = 3;
        }
        else
        {
            ++upDown;
        }
        break;
    case KEY_LEFT:
        if(leftRight == 0 && currentLayer == 0)
        {
            leftRight = cols + 4;
            currentLayer = 1;
        }
        else if(leftRight == 0 && currentLayer == 2)
        {
            leftRight = cols + 4;
            currentLayer = 3;
        }
        else if(leftRight == cols + 1 && currentLayer == 1)
        {
            leftRight -= 2;
            currentLayer = 0;
        }
        else if(leftRight == cols + 1 && currentLayer == 3)
        {
            leftRight -= 2;
            currentLayer = 2;
        }
        else
        {
            --leftRight;
        }
        break;
    case KEY_RIGHT:
        if(leftRight == cols + 4 && currentLayer == 1)
        {
            leftRight = 0;
            currentLayer = 0;
        }
        else if(leftRight == cols + 4 && currentLayer == 3)
        {
            leftRight = 0;
            currentLayer = 2;
        }
        else if(leftRight == cols - 1 && currentLayer == 0)
        {
            leftRight += 2;
            currentLayer = 1;
        }
        else if(leftRight == cols - 1 && currentLayer == 2)
        {
            leftRight += 2;
            currentLayer = 3;
        }
        else
        {
            ++leftRight;
        }
        break;
    case 111:
        if(upDown >= 5 && leftRight >= 5)
        {
            if(field[currentLayer][upDown - 5][leftRight - 5] == 0)
            {
                currentI = upDown - 5, currentJ = leftRight - 5;
                field[currentLayer][currentI][currentJ] = 1;
            }
        }
        else if(upDown >= 5)
        {
            if(field[currentLayer][upDown - 5][leftRight] == 0)
            {
                currentI = upDown - 5, currentJ = leftRight;
                field[currentLayer][currentI][currentJ] = 1;
            }
        }
        else if(leftRight >= 5)
        {
            if(field[currentLayer][upDown][leftRight - 5] == 0)
            {
                currentI = upDown, currentJ = leftRight - 5;
                field[currentLayer][currentI][currentJ] = 1;
            }
        }
        else
        {
            if(field[currentLayer][upDown][leftRight] == 0)
            {
                currentI = upDown, currentJ = leftRight;
                field[currentLayer][currentI][currentJ] = 1;
            }
        }
        break;
    case 120:
        if(upDown >= 5 && leftRight >= 5)
        {
            if(field[currentLayer][upDown - 5][leftRight - 5] == 0)
            {
                currentI = upDown - 5, currentJ = leftRight - 5;
                field[currentLayer][currentI][currentJ] = 2;
            }
        }
        else if(upDown >= 5)
        {
            if(field[currentLayer][upDown - 5][leftRight] == 0)
            {
                currentI = upDown - 5, currentJ = leftRight;
                field[currentLayer][currentI][currentJ] = 2;
            }
        }
        else if(leftRight >= 5)
        {
            if(field[currentLayer][upDown][leftRight - 5] == 0)
            {
                currentI = upDown, currentJ = leftRight - 5;
                field[currentLayer][currentI][currentJ] = 2;
            }
        }
        else
        {
            if(field[currentLayer][upDown][leftRight] == 0)
            {
                currentI = upDown, currentJ = leftRight;
                field[currentLayer][currentI][currentJ] = 2;
            }
        }
        break;
    }
    return 0;
}

int checkLine(int field[][4][4], int length, int i, int j, int k, int vi, int vj, int vk)
{
    int indicator = 0;
    for(int l = 0; l < length - 1; ++l)
    {
        if(field[i][j][k] != 0 && field[i][j][k] == field[i + vi][j + vj][k + vk])
        {
            ++indicator;
        }
        i += vi;
        j += vj;
        k += vk;
    }
    if(indicator == 3)
    {
        if(field[i][j][k] == 1)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    return 0;
}

int checkTheGame(int field[][4][4], int layers, int rows, int cols)
{
    int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0, J = 0, K = 0, amountOfUnusedCells = 0;
    A = checkLine(field, 4, currentLayer, 0, currentJ, 0, 1, 0);
    B = checkLine(field, 4, currentLayer, currentI, 0, 0, 0, 1);
    C = checkLine(field, 4, currentLayer, 0, 0, 0, 1, 1);
    D = checkLine(field, 4, currentLayer, rows - 1, 0, 0, -1, 1);
    E = checkLine(field, 4, 0, currentI, currentJ, 1, 0, 0);
    F = checkLine(field, 4, 0, rows - 1, currentJ, 1, -1, 0);
    G = checkLine(field, 4, 0, 0, currentJ, 1, 1, 0);
    H = checkLine(field, 4, 0, 0, 0, 1, 1, 1);
    I = checkLine(field, 4, 0, 0, cols - 1, 1, 1, -1);
    J = checkLine(field, 4, 0, rows - 1, 0, 1, -1, 1);
    K = checkLine(field, 4, 0, rows - 1, cols - 1, 1, -1, -1);
    if(A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0 || G != 0 || H != 0 || I != 0 || J != 0 || K != 0)
    {
        if(A != 0)
        {
            return A;
        }
        else if(B != 0)
        {
            return B;
        }
        else if(C != 0)
        {
            return C;
        }
        else if(D != 0)
        {
            return D;
        }
        else if(E != 0)
        {
            return E;
        }
        else if(F != 0)
        {
            return F;
        }
        else if(G != 0)
        {
            return G;
        }
        else if(H != 0)
        {
            return H;
        }
        else if(I != 0)
        {
            return I;
        }
        else if(J != 0)
        {
            return J;
        }
        else if(K != 0)
        {
            return K;
        }
    }
    for(int i = 0; i < layers; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            for(int k = 0; k < cols; ++k)
            {
                if(field[i][j][k] == 0)
                {
                    ++amountOfUnusedCells;
                }
            }
        }
    }
    if(amountOfUnusedCells == 0)
    {
        return 3;
    }
    return 0;
}
