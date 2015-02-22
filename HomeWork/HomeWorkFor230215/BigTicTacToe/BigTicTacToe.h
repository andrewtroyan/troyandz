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

enum Colors {normal, green, red, blue, yellow};

void treatSigWinch(int signo);
void initialiseProgram();
void drawField(int field[][20], int rows, int cols);
void playTheGame(int field[][20], int rows, int cols);
int checkTheGame(int field[][20], int rows, int cols);

#endif // BIGTICTACTOE_H_INCLUDED
