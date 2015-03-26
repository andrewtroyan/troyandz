#ifndef AKINATOR_H_INCLUDED
#define AKINATOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


typedef enum Type_ {animal, noanimal} Type;

typedef struct Data_
{
    Type type;
    char *str;
    int sizestr;
} Data;

typedef struct Node_
{
    Data data;
    struct Node_ *parent, *yeslink, *nolink;
} Node;

typedef struct NodeForStack_
{
    Node *node;
    struct NodeForStack_ *link;
} NodeForStack;

typedef NodeForStack * Stack;

void addNewFork(Node *oldAnimal, Node *newAnimal, Node *question, bool answer);
void hangFork(Node **root, Node *parent, Node *fork, bool wayToChild);
bool determineWayToChild(Node *node);
bool addNewKnowledge(Node **root, Node *destination, char *question, char *newAnimal, bool rightAnswer);
bool createNewNode(Node **node, char *str, Type type);

Node *playGame(Node *root);

bool addNode(Node **root, Node **parent, Data data, bool way);
bool AddNode2(Node **root, Node **node, int way, char *str, Type type);

bool push(Node *pointer, Stack *stack);
void pop(Stack *stack);
bool isEmpty(Stack stack);
bool onTop(Node **pointer, Stack stack);
void clearStack(Stack *stack);

#endif // AKINATOR_H_INCLUDED
