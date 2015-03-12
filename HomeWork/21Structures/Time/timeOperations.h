#ifndef TIMEOPERATIONS_H_INCLUDED
#define TIMEOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Time_
{
    long int hours, minutes, seconds;
} Time;

void enterTime(Time *);
void showTime(Time);
void addSeconds(Time *, long int);
long int differenceInSeconds(Time, Time);

#endif // TIMEOPERATIONS_H_INCLUDED
