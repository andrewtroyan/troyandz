#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSTR 100

typedef enum State_ {null, number, operator} State;

typedef struct Item_
{
    float number;
    char sign;
    State indicator;
} Item;

typedef struct Node_
{
    Item data;
    struct Node_ *link;
} Node;

typedef Node * List;
typedef Node * Stack;

int getPriority(char sign);
void setAsNumber(Item *pointer, float number);
void setAsOperator(Item *pointer, float operator);
void initializeList(List *pointer);
bool addToList(Item data, List *pointer);
void clearTheList(List *pointer);
void initializeStack(Stack *top);
void push(Item item, Stack *top);
void pop(Stack *top);
bool onTop(Item *item, Stack top);
void clearStack(Stack *top);

#endif // CALCULATOR_H_INCLUDED
