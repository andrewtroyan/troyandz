#include "LifeGame.h"

//bool memoryAlloc(int ****field)
//{
//    *field = (int ***)malloc(2 * sizeof(int **));
//    if(!(*field))
//        return false;
//
//    for(int i = 0; i < 2; ++i)
//    {
//        *(field[i]) = NULL;
//        *(field[i]) = (int **)malloc((SCREEN_HEIGHT / 10) * sizeof(int *));
//        if(!*(field[i]))
//        {
//            for(int index = i - 1; index >= 0; --index)
//            {
//                free(*(field[index]));
//                *(field[index]) = NULL;
//            }
//            free(*field);
//            *field = NULL;
//            return false;
//        }
//    }
//
//    for(int i = 0; i < 2; ++i)
//    {
//        for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
//        {
//            *(field[i][j]) = NULL;
//            *(field[i][j]) = (int *)malloc((SCREEN_WIDTH / 10) * sizeof(int));
//            if(!*(field[i][j]))
//            {
//                for(int i = 0; i < 2; ++i)
//                {
//                    for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
//                    {
//                        free(*(field[i][j]));
//                        *(field[i][j]) = NULL;
//                    }
//                    free(*(field[i]));
//                    *(field[i]) = NULL;
//                }
//                free(*field);
//                *field = NULL;
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//void clearField(int ****field)
//{
//    for(int i = 0; i < 2; ++i)
//    {
//        for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
//        {
//            free(*(field[i][j]));
//            *(field[i][j]) = NULL;
//        }
//        free(*(field[i]));
//        *(field[i]) = NULL;
//    }
//    free(*field);
//    *field = NULL;
//}

bool createAll(SDL_Window **win, SDL_Renderer **ren, char *name, int y, int x, int width, int height)
{
    if(SDL_Init(SDL_INIT_VIDEO))
        return false;
    if(!(*win = SDL_CreateWindow(name, y, x, width, height, SDL_WINDOW_SHOWN)))
        return false;
    if(!(*ren = SDL_CreateRenderer(*win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
        return false;
    return true;
}

void deleteAll(SDL_Window **win, SDL_Renderer **ren)
{
    SDL_DestroyRenderer(*ren);
    SDL_DestroyWindow(*win);
    SDL_Quit();
}

int aroundCell(int ***field, int z, int y, int x, int width, int height)
{
    int amountOfAliveCells = 0;
    for(int a = 0, i = (y - 1) % height; a < 3; i = (i + 1) % height, ++a)
    {
        for(int b = 0, j = (x - 1) % width; b < 3; j = (j + 1) % width, ++b)
        {
            amountOfAliveCells += field[z][i][j]? 1 : 0;
        }
    }
    return amountOfAliveCells;
}

void aroundField(int ***field, int width, int height, SDL_Renderer *ren)
{
    static int number = 0;
    SDL_Rect rect = {0, 0, 10, 10};
    for(int i = 0; i < height / 10; ++i)
    {
        for(int j = 0; j < width / 10; ++j)
        {
            int amount = aroundCell(field, number, i, j, width / 10, height / 10);
            if(!field[number][i][j] && amount == 3)
            {
                field[(number + 1) % 2][i][j] = 1;
                SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            else if(field[number][i][j] && (amount < 2 || amount > 3))
            {
                field[(number + 1) % 2][i][j] = 0;
                SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
            }
            rect.y = i * 10;
            rect.x = j * 10;
            SDL_RenderFillRect(ren, &rect);
        }
    }
    number = (number + 1) % 2;
}
