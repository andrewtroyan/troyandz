#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

void display(int **array, int rows, int cols);
void displayXO(int i);
void man(int **array);
void computer(int **array);
void motion(int **array, int where, int what);
int check(int **array);

#endif // TICTACTOE_H_INCLUDED
