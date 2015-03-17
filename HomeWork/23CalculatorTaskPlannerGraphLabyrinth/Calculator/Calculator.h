#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

typedef enum State_ {number, operator} State;

typedef struct Item_
{
    double number;
    char sign;
    State indicator;
} Item;

typedef struct Node_
{
    Item data;
    struct Node_ *next;
} Node;

#endif // CALCULATOR_H_INCLUDED
