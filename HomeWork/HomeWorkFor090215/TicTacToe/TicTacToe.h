#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

#define MAXROWS 4
#define MAXCOLS 4

void fillArrayWithEmptySymbols(char array[][MAXCOLS], int rows, int cols);
void showTable(char array[][MAXCOLS], int rows, int cols);
void fillTable(char array[][MAXCOLS]);
char checkFinish(char array[][MAXCOLS]);
void playTheGame(char array[][MAXCOLS], int rows, int cols);

#endif // TICTACTOE_H_INCLUDED
