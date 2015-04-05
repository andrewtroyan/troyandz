#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 640

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *win = SDL_CreateWindow("Moving start", 100, 100, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);

    if(!win)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    if(!IMG_Init(IMG_INIT_PNG))
    {
        fprintf(stderr, "IMG_Init Error: %s\n", IMG_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!ren)
    {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        IMG_Quit();
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(1);
    }

    SDL_Surface *png = IMG_Load("../../MediaResources/star.png");

    if(!png)
    {
        fprintf(stderr, "IMG_Load Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(ren);
        IMG_Quit();
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(1);
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, png);
    SDL_FreeSurface(png);

    if(!tex)
    {
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(ren);
        IMG_Quit();
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(1);
    }

    int x0 = SCREEN_WIDTH / 2 - 32, y0 = SCREEN_HEIGHT / 2 - 32;
    SDL_Rect dstRect = {0, 0, 64, 64};
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0x00, 0xFF);
    SDL_RenderClear(ren);

    for(double i = 0; i < 360; i += 30)
    {
        dstRect.x = x0 + sin(i * 3.14 / 180) * x0;
        dstRect.y = y0 + cos(i * 3.14 / 180) * y0;
        SDL_RenderCopy(ren, tex, NULL, &dstRect);
    }

    SDL_RenderPresent(ren);
    SDL_Delay(5000);

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    IMG_Quit();
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
