#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

typedef enum State_ {number, operator} State;

typedef struct Item_
{
    float number;
    char sign;
    State indicator;
} Item;

typedef struct Node_
{
    Item data;
    struct Node_ *next;
} Node;

typedef Node * List;

#endif // CALCULATOR_H_INCLUDED
