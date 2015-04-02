#include "LifeGame.h"

int main()
{
    SDL_Window *win = NULL;
    SDL_Renderer *ren = NULL;
    if(!createAll(&win, &ren, "Life Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        fprintf(stderr, "%s", SDL_GetError());
        exit(1);
    }

//-----

    int ***field = NULL;

    field = (int ***)malloc(2 * sizeof(int **));
    if(!field)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    for(int i = 0; i < 2; ++i)
    {
        field[i] = NULL;
        field[i] = (int **)malloc((SCREEN_HEIGHT / 10) * sizeof(int *));
        if(!field[i])
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

    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
        {
            field[i][j] = NULL;
            field[i][j] = (int *)malloc((SCREEN_WIDTH / 10) * sizeof(int));
            if(!field[i][j])
            {
                for(int i = 0; i < 2; ++i)
                {
                    for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
                    {
                        free(field[i][j]);
                        field[i][j] = NULL;
                    }
                    free(field[i]);
                    field[i] = NULL;
                }
                free(field);
                field = NULL;
                fprintf(stderr, "No free memory.\n");
                exit(1);
            }
        }
    }

    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
            for(int k = 0; k < SCREEN_WIDTH / 10; ++k)
                field[i][j][k] = 0;

//-----

    SDL_Rect rect = {0, 0, 10, 10};
    SDL_Event event;
    State indicator = keep;
    bool indicatorOfClick = false;

    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

    while(indicator == keep)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                indicator = quit;
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                indicatorOfClick = true;
                SDL_MouseButtonEvent mouse = event.button;
                field[1][mouse.y / 10][mouse.x / 10] = 1;
                rect.y = mouse.y - mouse.y % 10;
                rect.x = mouse.x - mouse.x % 10;
                SDL_RenderFillRect(ren, &rect);
                SDL_RenderPresent(ren);
            }
            if(event.type == SDL_KEYDOWN)
            {
                SDL_KeyboardEvent kEvent = event.key;
                if(kEvent.keysym.scancode == SDL_SCANCODE_RETURN && indicatorOfClick)
                    indicator = start;
                else if(kEvent.keysym.scancode == SDL_SCANCODE_RETURN && !indicatorOfClick)
                    indicator = quit;
            }
        }
    }

    while(indicator == start)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.scancode == SDL_SCANCODE_RETURN)
                    indicator = quit;
            }
            else
            {
                SDL_RenderClear(ren);
                aroundField(field, SCREEN_WIDTH, SCREEN_HEIGHT, ren);
                SDL_RenderPresent(ren);
            }
        }
    }

//-----

    deleteAll(&win, &ren);

    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < SCREEN_HEIGHT / 10; ++j)
        {
            free(field[i][j]);
            field[i][j] = NULL;
        }
        free(field[i]);
        field[i] = NULL;
    }
    free(field);
    field = NULL;

    return 0;
}
