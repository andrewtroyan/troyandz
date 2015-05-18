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
typedef Node * Stack;
typedef struct Queue_
{
    Node *head, *tail;
} Queue;

// ---LIST---

void initializeList(List *pointer);
bool addToList(int data, List *pointer);
void clearTheList(List *pointer);

// ---STACK---

void initializeStack(Stack *pointer);
bool pushToStack(int data, Stack *pointer);
void popFromStack(Stack *pointer);
bool isStackEmpty(Stack pointer);
bool onTopOfStack(int *data, Stack pointer);
void clearStack(Stack *pointer);

// ---QUEUE---

void initializeQueue(Queue *pointer);
bool addToQueue(int data, Queue *pointer);
void popFromQueue(Queue *pointer);
bool isQueueEmpty(Queue pointer);
bool onTopOfQueue(int *data, Queue pointer);
void clearQueue(Queue *pointer);

// ---Work with data structures---

void showList(List pointer);
void workOnStack(int firstNode, State *arrayOfStates, List *arrayOfLists, List *listForWay);
void workOnQueue(int firstNode, State *arrayOfStates, List *arrayOfLists, List *listForWay);
void clearStructures(List **arrayOfLists, int amountOfNodes, List *ListForWay, State **arrayOfStates);

#endif // DEPTH_H_INCLUDED
