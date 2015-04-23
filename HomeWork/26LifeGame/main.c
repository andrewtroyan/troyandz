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
    if(!memoryAlloc(&field))
    {
        fprintf(stderr, "No free memory.\n");
        clearField(&field);
        deleteAll(&win, &ren);
        exit(1);
    }

//-----

    CurrentCell currentCell = {0, 0};
    State indicator = keep;
    SDL_Event event;

    while(indicator == keep)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                indicator = quit;
            else if(event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_RETURN)
                indicator = start;
            else if(event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN)
                enterData(field, event, &currentCell, SCREEN_WIDTH, SCREEN_HEIGHT);
        }
        showField(field, ren, currentCell, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    while(indicator == start)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                indicator = quit;
            if(event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_RETURN)
                indicator = quit;
        }
        if(!play(field, ren, SCREEN_WIDTH, SCREEN_HEIGHT))
            indicator = quit;
    }

//-----

    deleteAll(&win, &ren);
    clearField(&field);
    return 0;
}
