#ifndef CATOPERATIONS_H_INCLUDED
#define CATOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

void printNumbers(char **, FILE *, char *);
void printNumbersNonBlanks(char **, FILE *, char *);
void printHelp(FILE *, char *);
void catFiles(char **, FILE *, char *);

#endif // CATOPERATIONS_H_INCLUDED
