#ifndef LISSAJOUS_H_INCLUDED
#define LISSAJOUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>

#define SCREEN_HIGHT 640
#define SCREEN_WIDTH 640

#define PI 3.14159265

typedef enum State_ {quit, show, turn} State;

bool createAll(SDL_Window **win, SDL_Renderer **ren, char *name, int y, int x, int width, int height);
void deleteAll(SDL_Window **win, SDL_Renderer **ren);
void drawLissajousFigure(SDL_Renderer *ren, int m, int n);
void turnLissajousFigure(SDL_Renderer *ren, int m, int n, State *indicator);

#endif // LISSAJOUS_H_INCLUDED
