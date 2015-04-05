#include "Lissajous.h"

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

void drawLissajousFigure(SDL_Renderer *ren, int m, int n)
{
    int x, y;
    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
    for(double i = 0; i <= 180; i += 0.01)
    {
        x = (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 2) * cos(m * i), y = (SCREEN_HIGHT / 2) + (SCREEN_HIGHT / 2) * sin(n * i);
        SDL_RenderDrawPoint(ren, x, y);
    }
    SDL_RenderPresent(ren);
}


void turnLissajousFigure(SDL_Renderer *ren, int m, int n, State *indicator)
{
    int x, y;
    double j = 0;
    bool quit = false;
    SDL_Event event;
    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                *indicator = quit;
                quit = true;
            }
            else if(event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_RETURN)
            {
                *indicator = quit;
                quit = true;
            }
        }
        if(!quit)
        {
            SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
            for(double i = 0; i <= 180; i += 0.01)
            {
                x = (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 2) * cos(m * i), y = (SCREEN_HIGHT / 2) + (SCREEN_HIGHT / 2) * sin(n * i + j);
                SDL_RenderDrawPoint(ren, x, y);
            }
            SDL_RenderPresent(ren);
            j += 0.01;
        }
    }
}
