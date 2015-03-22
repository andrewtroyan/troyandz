#ifndef SHORTESTWAYSEARCH_H_INCLUDED
#define SHORTESTWAYSEARCH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node_
{
    int node, weightOfEdge;
} Node;

typedef struct AlliedNode_
{
    Node NodeToAlly;
    struct AlliedNode_ *link;
} AlliedNode;

typedef AlliedNode * ListOfAlliedNodes;

bool addToListOfAlliedNodes(int node, int weightOfEdge, ListOfAlliedNodes *pointer);
void clearListOfAlliedNodes(ListOfAlliedNodes *pointer);

// -----

enum State {flagged, unflagged};

typedef struct NodeForAnalyze_
{
    int destination, from, indicator;
} NodeForAnalyze;

void initializeAnalyzeList(NodeForAnalyze *array, int amountOfNodes, int from);
int minOfAnalyzeList(NodeForAnalyze *array, int amountOfNodes);
void analyze(ListOfAlliedNodes *array, NodeForAnalyze *analyzeArray, int amountOfNodes, int to);

// -----

void push(int *stack, int *top, int value);
bool isEmpty(int top);
void pop(int *stack, int *top);
void clearStack(int *stack, int *top);
int onTop(int *stack, int top);

#endif // SHORTESTWAYSEARCH_H_INCLUDED
