#ifndef BIGTICTACTOE_H_INCLUDED
#define BIGTICTACTOE_H_INCLUDED

#include "../../../modules/include/ncursesDetails.h"

#define ROWS 20
#define COLS 20

void drawField(int **field);
void playTheGame(int **field);
int checkTheGame(int **field);

#endif // BIGTICTACTOE_H_INCLUDED
