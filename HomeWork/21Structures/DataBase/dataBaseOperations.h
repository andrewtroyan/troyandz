#ifndef DATABASEOPERATIONS_H_INCLUDED
#define DATABASEOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSTR 30
#define MAXAMOUNT 50

typedef struct Town_
{
    char name[MAXSTR], country[MAXSTR], language[MAXSTR];
    double area;
    long int population;
} Town;

#endif // DATABASEOPERATIONS_H_INCLUDED
