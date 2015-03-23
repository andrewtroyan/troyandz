#include "Labyrinth.h"

void drawField(Node **field, int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            move(i, j);
            if(field[i][j].state == board || (field[i][j].state == closed))
                attron(A_REVERSE);
            printw(" ");
            if(field[i][j].state == board || (field[i][j].state == closed))
                attroff(A_REVERSE);
        }
    }
}
