#ifndef AKINATOR_H_INCLUDED
#define AKINATOR_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstdbool>
#include <cstring>

typedef enum Type_ {animal, noanimal} Type;

struct Data
{
    Type type;
    char *str;
    int sizestr;
};

struct Node
{
    Data data;
    Node *parent, *yeslink, *nolink;
};


struct NodeForStack
{
    Node *node;
    NodeForStack *link;
};

typedef NodeForStack * Stack;

// -----

namespace tree
{
void addNewFork(Node *oldAnimal, Node *newAnimal, Node *question, bool answer);
void hangFork(Node **root, Node *parent, Node *fork, bool wayToChild);
bool determineWayToChild(Node *node);
void addNewKnowledge(Node **root, Node *destination, char *question, char *newAnimal, bool rightAnswer);
void createNewNode(Node **node, char *str, Type type);
void addNode(Node **root, Node **node, int way, char *str, Type type);
void addNewInformation(Node **root, Node *destination);
void clearTree(Node **root);
}

// -----

namespace game
{
Node *playGame(Node *root);
}

// -----

namespace stack
{
void pushToStack(Node *pointer, Stack *stack);
void popFromStack(Stack *stack);
bool isStackEmpty(Stack stack);
bool onTopOfStack(Node **pointer, Stack stack);
void clearStack(Stack *stack);
}

// -----

namespace file
{
bool readFromFile(FILE *filepointer, Node **root);
void writeToFile(FILE *filepointer, Node *root);
}

#endif // AKINATOR_H_INCLUDED
