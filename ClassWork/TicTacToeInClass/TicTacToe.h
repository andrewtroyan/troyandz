#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

void display(int array[][3], int rows, int cols);
void displayXO(int i);
void man(int array[][3]);
void computer(int array[][3]);
void motion(int array[][3], int where, int what);
int check(int array[][3]);

#endif // TICTACTOE_H_INCLUDED
