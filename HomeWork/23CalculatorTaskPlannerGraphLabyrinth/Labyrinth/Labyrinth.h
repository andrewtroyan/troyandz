#ifndef LABYRINTH_H_INCLUDED
#define LABYRINTH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../Modules/include/ncursesDetails.h"

typedef enum StateOfNode_ {board, open, closed} StateOfNode;

typedef struct Node_
{
    int i, j;
    StateOfNode state;
} Node;

void drawField(Node **field, int rows, int cols);

#endif // LABYRINTH_H_INCLUDED
