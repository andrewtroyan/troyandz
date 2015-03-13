#ifndef DATABASEOPERATIONS_H_INCLUDED
#define DATABASEOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSTR 30
#define MAXAMOUNT 10

typedef struct Town_
{
    char name[MAXSTR], country[MAXSTR], language[MAXSTR];
    double area;
    long int population;
} Town;

void downloadFromFile(Town *);
void downloadToFile(Town *);
bool addData(Town *);
bool deleteData(Town *);
void showData(Town *);
void quickSorting(Town *, int, int, bool (*)(Town, Town));
bool sortNameFromLittleToBig(Town, Town);
bool sortNameFromBigToLittle(Town, Town);
bool sortCountryFromLittleToBig(Town, Town);
bool sortCountryFromBigToLittle(Town, Town);
bool sortLanguageFromLittleToBig(Town, Town);
bool sortLanguageFromBigToLittle(Town, Town);
bool sortAreaFromLittleToBig(Town, Town);
bool sortAreaFromBigToLittle(Town, Town);
bool sortPopulationFromLittleToBig(Town, Town);
bool sortPopulationFromBigToLittle(Town, Town);

#endif // DATABASEOPERATIONS_H_INCLUDED
