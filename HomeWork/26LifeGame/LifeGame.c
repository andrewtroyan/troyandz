#include "LifeGame.h"

bool memoryAlloc(int ****field)
{
    *field = (int ***)malloc(2 * sizeof(int **));
    if(!(*field))
        return false;

    for(int i = 0; i < 2; ++i)
    {
        field[0][i] = NULL;
        field[0][i] = (int **)malloc((SCREEN_HEIGHT / 10) * sizeof(int *));
        if(!field[0][i])
        {
            for(int index = i - 1; index >= 0; --index)
            {
                free(field[0][index]);
                field[0][index] = NULL;
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
            field[0][i][j] = NULL;
            field[0][i][j] = (int *)malloc((SCREEN_WIDTH / 10) * sizeof(int));
            if(!field[0][i][j])
            {
                for(int i = 0; i < 2; ++i)
                {
                    for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
                    {
                        free(field[0][i][j]);
                        field[0][i][j] = NULL;
                    }
                    free(field[0][i]);
                    field[0][i] = NULL;
                }
                free(*field);
                *field = NULL;
                return false;
            }
            else
            {
                for(int k = 0; k < SCREEN_WIDTH / 10; ++k)
                    field[0][i][j][k] = 0;
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
            free(field[0][i][j]);
            field[0][i][j] = NULL;
        }
        free(field[0][i]);
        field[0][i] = NULL;
    }
    free(*field);
    *field = NULL;
}

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

void enterData(int ***field, SDL_Event event, CurrentCell *currentCell, int width, int height)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        SDL_MouseButtonEvent mouse = event.button;
        field[0][mouse.y / 10][mouse.x / 10] = (field[0][mouse.y / 10][mouse.x / 10] + 1) % 2;
    }
    if(event.type == SDL_KEYDOWN)
    {
        SDL_KeyboardEvent kEvent = event.key;

        if(kEvent.keysym.scancode == SDL_SCANCODE_UP)
            currentCell->y = (height / 10 + currentCell->y - 1) % (height / 10);
        else if(kEvent.keysym.scancode == SDL_SCANCODE_DOWN)
            currentCell->y = (currentCell->y + 1) % (height / 10);
        else if(kEvent.keysym.scancode == SDL_SCANCODE_LEFT)
            currentCell->x = (width / 10 + currentCell->x - 1) % (width / 10);
        else if(kEvent.keysym.scancode == SDL_SCANCODE_RIGHT)
            currentCell->x = (currentCell->x + 1) % (width / 10);
        else if(kEvent.keysym.scancode == SDL_SCANCODE_SPACE)
            field[0][currentCell->y][currentCell->x] = (field[0][currentCell->y][currentCell->x] + 1) % 2;
    }
}

void showField(int ***field, SDL_Renderer *ren, CurrentCell currentCell, int width, int height)
{
    SDL_RenderClear(ren);
    SDL_Rect rect = {0, 0, 10, 10};
    for(int i = 0; i < height / 10; ++i)
    {
        for(int j = 0; j < width / 10; ++j)
        {
            if(field[0][i][j])
            {
                if(i == currentCell.y && j == currentCell.x)
                    SDL_SetRenderDrawColor(ren, 0xFF, 0x00, 0x00, 0xFF);
                else
                    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            else
            {
                if(i == currentCell.y && j == currentCell.x)
                    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0xFF, 0xFF);
                else
                    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
            }
            rect.y = i * 10;
            rect.x = j * 10;
            SDL_RenderFillRect(ren, &rect);
        }
    }
    SDL_RenderPresent(ren);
}

bool play(int ***field, SDL_Renderer *ren, int width, int height)
{
    bool indicator = false;
    SDL_RenderClear(ren);
    indicator = aroundField(field, SCREEN_WIDTH, SCREEN_HEIGHT, ren);
    SDL_RenderPresent(ren);
    SDL_Delay(100);
    return indicator;
}

bool aroundField(int ***field, int width, int height, SDL_Renderer *ren)
{
    static int number = 0;
    SDL_Rect rect = {0, 0, 10, 10};
    bool indicatorToContinue = false;
    for(int i = 0; i < height / 10; ++i)
    {
        for(int j = 0; j < width / 10; ++j)
        {
            int amount = aroundCell(field, number, i, j, width / 10, height / 10);
            if(!field[number][i][j])
            {
                if(amount == 3)
                {
                    field[(number + 1) % 2][i][j] = 1;
                    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
                }
                else
                {
                    field[(number + 1) % 2][i][j] = 0;
                    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
                }
            }
            else if(field[number][i][j])
            {
                indicatorToContinue = true;
                if(amount < 2 || amount > 3)
                {
                    field[(number + 1) % 2][i][j] = 0;
                    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
                }
                else
                {
                    field[(number + 1) % 2][i][j] = 1;
                    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
                }
            }
            rect.y = i * 10;
            rect.x = j * 10;
            SDL_RenderFillRect(ren, &rect);
        }
    }
    number = (number + 1) % 2;
    return indicatorToContinue;
}

int aroundCell(int ***field, int number, int y, int x, int width, int height)
{
    int amountOfAliveCells = 0;
    for(int a = 0, i = (height + y - 1) % height; a < 3; i = (i + 1) % height, ++a)
    {
        for(int b = 0, j = (width + x - 1) % width; b < 3; j = (j + 1) % width, ++b)
        {
            if((i != y || j != x) && field[number][i][j])
                ++amountOfAliveCells;
        }
    }
    return amountOfAliveCells;
}
