#ifndef NCURSESDETAILS_H_INCLUDED
#define NCURSESDETAILS_H_INCLUDED

#define _XOPEN_SOURCE_EXTENDED
//#define _POSIX_C_SOURCE 199309L

#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>

enum Colors {normal, green, red, blue, yellow};

void treatSigWinch(int signo);
void initialiseProgram();

#endif // NCURSESDETAILS_H_INCLUDED
