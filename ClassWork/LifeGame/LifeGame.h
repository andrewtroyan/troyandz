#ifndef LIFEGAME_H_INCLUDED
#define LIFEGAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef enum State_ {keep, quit, start} State;

//bool memoryAlloc(int ****field);
//void clearField(int ****field);
bool createAll(SDL_Window **win, SDL_Renderer **ren, char *name, int y, int x, int width, int height);
void deleteAll(SDL_Window **win, SDL_Renderer **ren);
int aroundCell(int ***field, int z, int y, int x, int width, int height);
void aroundField(int ***field, int width, int height, SDL_Renderer *ren);

#endif // LIFEGAME_H_INCLUDED
