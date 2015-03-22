#include "Labyrinth.h"

int main()
{
    int rows, cols;
    Node **field = NULL;
    printf("Enter amount of rows: ");
    scanf("%d", &rows);
    field = (Node **)malloc(rows * sizeof(Node *));
    if(field == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    printf("Enter amount of cols: ");
    scanf("%d", &cols);
    for(int i = 0; i < rows; ++i)
    {
        field[i] = NULL;
        field[i] = (Node *)malloc(cols * sizeof(Node));
        if(field [i] == NULL)
        {
            for(int index = i - 1; index >= 0; --index)
            {
                free(field[index]);
                field[index] = NULL;
            }
            free(field);
            field = NULL;
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
    }
// -----
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            field[i][j].i = i;
            field[i][j].j = j;
            field[i][j].state = closed;
        }
    }

    for(int i = 0; i < rows; ++i)
    {
        field[i][0].state = board;
        field[i][cols - 1].state = board;
    }

    for(int i = 1; i < cols - 1; ++i)
    {
        field[0][i].state = board;
        field[rows - 1][i].state = board;
    }
// -----
    initialiseProgram();
    drawField(field, rows, cols);
// -----
    for(int i = 0; i < rows; ++i)
    {
        free(field[i]);
        field[i] = NULL;
    }
    free(field);
    field = NULL;
// -----
    getch();
    endwin();
    return 0;
}
