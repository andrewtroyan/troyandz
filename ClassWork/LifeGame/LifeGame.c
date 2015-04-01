#include "LifeGame.h"

bool memoryAlloc(int ****field)
{
    *field = (int ***)malloc(2 * sizeof(int **));
    if(!(*field))
        return false;

    for(int i = 0; i < 2; ++i)
    {
        *(field[i]) = NULL;
        *(field[i]) = (int **)malloc((SCREEN_HEIGHT / 10) * sizeof(int *));
        if(!*(field[i]))
        {
            for(int index = i - 1; index >= 0; --index)
            {
                free(*(field[index]));
                *(field[index]) = NULL;
            }
            free(*field);
            *field = NULL;
            return false;
        }
    }

    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
        {
            *(field[i][j]) = NULL;
            *(field[i][j]) = (int *)malloc((SCREEN_WIDTH / 10) * sizeof(int));
            if(!*(field[i][j]))
            {
                for(int i = 0; i < 2; ++i)
                {
                    for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
                    {
                        free(*(field[i][j]));
                        *(field[i][j]) = NULL;
                    }
                    free(*(field[i]));
                    *(field[i]) = NULL;
                }
                free(*field);
                *field = NULL;
                return false;
            }
        }
    }
    return true;
}

void clearField(int ****field)
{
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
        {
            free(*(field[i][j]));
            *(field[i][j]) = NULL;
        }
        free(*(field[i]));
        *(field[i]) = NULL;
    }
    free(*field);
    *field = NULL;
}
