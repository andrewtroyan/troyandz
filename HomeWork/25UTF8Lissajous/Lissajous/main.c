#include "Lissajous.h"

int main()
{
    SDL_Window *win;
    SDL_Renderer *ren;

    if(!createAll(&win, &ren, "Lissajous", 100, 100, SCREEN_WIDTH, SCREEN_HIGHT))
    {
        fprintf(stderr, "%s", SDL_GetError());
        deleteAll(&win, &ren);
        exit(1);
    }

    State indicator = show;
    int m = 1, n = 1;
    SDL_Event event;

    while(indicator != quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                indicator = quit;
            else if(event.type == SDL_KEYDOWN)
            {
                SDL_KeyboardEvent key = event.key;
                if(key.keysym.scancode == SDL_SCANCODE_UP)
                    ++m;
                if(key.keysym.scancode == SDL_SCANCODE_DOWN)
                    m -= m > 1? 1 : 0;
                if(key.keysym.scancode == SDL_SCANCODE_LEFT)
                    n -= n > 1? 1 : 0;
                if(key.keysym.scancode == SDL_SCANCODE_RIGHT)
                    ++n;
                if(key.keysym.scancode == SDL_SCANCODE_RETURN)
                    indicator = turn;
            }
        }
        if(indicator == show)
            drawLissajousFigure(ren, m, n);
        else if(indicator == turn)
            turnLissajousFigure(ren, m, n, &indicator);
    }

    deleteAll(&win, &ren);
    return 0;
}
