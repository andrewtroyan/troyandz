#include "LifeGame.h"

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *win = SDL_CreateWindow("Life Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(!win)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!ren)
    {
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }


    SDL_Rect rect = {0, 0, 10, 10};
    SDL_Event e;

    int ***field = NULL;
    if(!memoryAlloc(&field))
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    State indicator = keep;

    while(indicator == keep)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
                indicator = quit;
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                //зафиксить пложение курсора
                //занести в таблицу
            }
            if(e.type == SDL_KEYDOWN)
            {
                SDL_KeyboardEvent kEvent = e.key;
                if(kEvent.keysym.scancode == SDL_SCANCODE_RETURN)
                {
                    indicator = start;
                }
            }
        }

        SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRect(ren, &rect);
        SDL_RenderPresent(ren);
    }

    if(indicator == start)
    {
        while(indicator != quit)
        {
            while(SDL_PollEvent(&e))
            {
                if(e.type == SDL_KEYDOWN)
                {
                    SDL_KeyboardEvent kEvent = e.key;
                    if(kEvent.keysym.scancode == SDL_SCANCODE_SPACE)
                        indicator = quit;
                }
                else
                {
                    //обход
                }
            }
            //обход ???
        }
    }

    clearField(&field);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
