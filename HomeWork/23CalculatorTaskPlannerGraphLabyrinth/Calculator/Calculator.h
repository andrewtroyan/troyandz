#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAXSTR 100

typedef enum State_ {null = 0, num, symbol} State;

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
void setAsOperator(Item *pointer, char sign);
void initializeList(List *pointer);
bool addToList(Item data, List *pointer);
void clearTheList(List *pointer);
void initializeStack(Stack *top);
void push(Item item, Stack *top);
void pop(Stack *top);
bool onTop(Item *item, Stack top);
void clearStack(Stack *top);
void workOnNodes(List list, Stack *stack, void (*function)(Item item, Stack *stack));
void workOnEveryNode(Item item, Stack *stack);
void workOnOperator(char sign, Stack *stack);
void turnToPostfix(List *postfixNotation, Stack *stack, char *string);

#endif // CALCULATOR_H_INCLUDED
