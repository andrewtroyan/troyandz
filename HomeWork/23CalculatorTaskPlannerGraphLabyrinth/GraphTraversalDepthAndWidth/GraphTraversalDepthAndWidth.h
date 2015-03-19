#ifndef DEPTH_H_INCLUDED
#define DEPTH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum State_ {unflagged, flagged} State;

typedef struct Node_
{
    int data;
    struct Node_ *link;
} Node;

typedef Node * List;

void initializeList(List *pointer);
bool addToList(int data, List *pointer);
void clearTheList(List *pointer);
void printList(List list);

#endif // DEPTH_H_INCLUDED
