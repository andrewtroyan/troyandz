#ifndef CALENDAROPERATIONS_H_INCLUDED
#define CALENDAROPERATIONS_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef struct Date_
{
    int year, month, day;
} Date;

int enterDate(Date *);
void showDate(Date);
bool isLeapYear(int);
bool checkDate(Date);
long int amountOfDays(Date);
void addDays(Date *, long int);
int differenceInDays(Date, Date);

#endif // CALENDAROPERATIONS_H_INCLUDED
