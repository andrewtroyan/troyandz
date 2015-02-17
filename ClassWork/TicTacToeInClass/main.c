#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TicTacToe.h"

int main()
{
    int table[3][3] = {0};
    bool comp = false, game = true;
    while(game)
    {
        system("clear");
        display(table, 3, 3);
        if(comp)
        {
            computer(table);
        }
        else
        {
            man(table);
        }
        int r = check(table);
        switch (r)
        {
        case 1:
            comp = !comp;
            break;
        case 2:
            system("clear");
            display(table, 3, 3);
            printf("Draw!\n");
            game = false;
            break;
        case 3:
            system("clear");
            display(table, 3, 3);
            printf("Computer won!\n");
            game = false;
            break;
        case 4:
            system("clear");
            display(table, 3, 3);
            printf("You won!\n");
            game = false;
            break;
        }
    }
    return 0;
}
