#ifndef LIFEGAME_H_INCLUDED
#define LIFEGAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef enum State_ {keep, quit, start} State;

bool memoryAlloc(int ****field);
void clearField(int ****field);

#endif // LIFEGAME_H_INCLUDED
