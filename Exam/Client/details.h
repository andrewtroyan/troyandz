#ifndef DETAILS_H_INCLUDED
#define DETAILS_H_INCLUDED

#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE 199309L

#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "ncursesDetails.h"

#define MESSAGE_LENGTH 512
#define NAME_LENGTH 32

typedef struct SocketInfo_
{
    char name[NAME_LENGTH], message[MESSAGE_LENGTH];
    int amountOfOnline;
} SocketInfo;

typedef struct ThreadInfo_
{
    WINDOW **listOfWindows;
    int socket;
    char name[NAME_LENGTH];
} ThreadInfo;

int setWindows(WINDOW ***wins, int rows, int cols);
void deleteWindows(WINDOW ***wins);
void *readFromServer(void *arg);

#endif // DETAILS_H_INCLUDED
