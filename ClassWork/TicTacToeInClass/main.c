#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TicTacToe.h"

int main()
{
    int **table = NULL;

    table = (int **)malloc(3 * sizeof(int*));
    if(table == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    for(int i = 0; i < 3; ++i)
    {
        table[i] = NULL;
        table[i] = (int *)malloc(3 * sizeof(int));
        if(table[i] == NULL)
        {
            for(int index = i; index > 0; --index)
            {
                free(table[index - 1]);
                table[index - 1] = NULL;
            }
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
    }

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
    for(int i = 0; i < 3; ++i)
    {
        free(table[i]);
        table[i] = NULL;
    }

    free(table);
    table = NULL;

    return 0;
}
