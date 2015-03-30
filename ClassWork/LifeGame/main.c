#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *win = SDL_CreateWindow("Life Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOWEVENT_SHOWN);

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

    bool quit = false;

    while(!quit)
    {
        while(SDL_PollEvent(&e)) //User requests quit
        {
            if(e.type == SDL_QUIT)
                quit = true;
            if(e.type == SDL_KEYDOWN)
            {
                SDL_KeyboardEvent kEvent = e.key;
                switch(kEvent.keysym.scancode)
                {
                case SDL_SCANCODE_A:
                    rect.x = (rect.x - 10 + SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_D:
                    rect.x = (rect.x + 10 + SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_W:
                    rect.y = (rect.y - 10 + SCREEN_HEIGHT) % SCREEN_HEIGHT;
                    break;
                case SDL_SCANCODE_S:
                    rect.y = (rect.y + 10 + SCREEN_HEIGHT) % SCREEN_HEIGHT;
                    break;
                }
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)
                quit = true;
        }


        SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRect(ren, &rect);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
