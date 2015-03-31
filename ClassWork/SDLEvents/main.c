#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main()
{
    //инициализация SDL
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *win = SDL_CreateWindow("Hello world!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

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

    SDL_Surface *bmp = SDL_LoadBMP("hello.bmp");

    if(!bmp)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);

    if(!tex)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    //Now lets draw our image
    //First clear the renderer
    SDL_RenderClear(ren);

    //Draw the texture
    SDL_RenderCopy(ren, tex, NULL, NULL);

    bool quit = false;

    SDL_Event e;

    int x = 10, y = 10;

    while(!quit)
    {
        while(SDL_PollEvent(&e)) //User requests quit
        {
            if(e.type == SDL_QUIT)
                quit = true;
            if(e.type == SDL_KEYDOWN)
            {
                SDL_KeyboardEvent kEvent = e.key;
                /*if(kEvent.keysym.scancode == SDL_SCANCODE_A)
                    x = (x - 1 + SCREEN_WIDTH) % SCREEN_WIDTH;*/
                switch(kEvent.keysym.scancode)
                {
                case SDL_SCANCODE_A:
                    x = (x - 10 + SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_D:
                    x = (x + 10 + SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_W:
                    y = (y - 10 + SCREEN_HEIGHT) % SCREEN_HEIGHT;
                    break;
                case SDL_SCANCODE_S:
                    y = (y + 10 + SCREEN_HEIGHT) % SCREEN_HEIGHT;
                    break;
                }
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)
                quit = true;
        }

        SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(ren);
        //SDL_RenderCopy(ren, tex, NULL, NULL);
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawLine(ren, x, y, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        //SDL_RenderDrawPoint(ren, x, y);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
