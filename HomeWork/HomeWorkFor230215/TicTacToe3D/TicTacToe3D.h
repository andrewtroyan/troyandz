#ifndef BIGTICTACTOE_H_INCLUDED
#define BIGTICTACTOE_H_INCLUDED

#include "../../../modules/include/ncursesDetails.h"

#define LAYERS 4
#define ROWS 4
#define COLS 4

void drawField(int ***field);
void playTheGame(int ***field);
int checkTheGame(int ***field);

#endif // BIGTICTACTOE_H_INCLUDED
