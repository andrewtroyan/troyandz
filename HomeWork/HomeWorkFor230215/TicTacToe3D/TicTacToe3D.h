#ifndef BIGTICTACTOE_H_INCLUDED
#define BIGTICTACTOE_H_INCLUDED

#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE 199309L

#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#define LAYERS 4
#define ROWS 4
#define COLS 4

enum Colors {normal, green, red, blue, yellow};

void treatSigWinch(int signo);
void initialiseProgram();
void drawField(int ***field);
void playTheGame(int ***field);
int checkTheGame(int ***field);

#endif // BIGTICTACTOE_H_INCLUDED
