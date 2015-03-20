#ifndef RR_H_INCLUDED
#define RR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---

typedef struct Process_
{
    int identifier, comingTime, runningTime;
} Process;

typedef struct RunnedProcess_
{
    int identifier, waitingTime, runningTime;
} RunnedProcess;

// ---

typedef struct RunningNode_
{
    Process process;
    struct RunningNode_ *link;
} RunningNode;

typedef struct RunnedNode_
{
    RunnedProcess runnedProcess;
    struct RunnedNode_ *link;
} RunnedNode;

// ---

typedef struct Queue_
{
    RunningNode *head, *tail;
} Queue;

typedef RunningNode * ListOfUnbornProcesses;

typedef RunnedNode * ListOfRunnedPartsOfProcesses;

// ---QUEUE---

void initializeQueue(Queue *pointer);
bool addToQueue(Process data, Queue *pointer);
void popFromQueue(Queue *pointer);
bool isQueueEmpty(Queue pointer);
void onHeadOfQueue(Process *process, Queue pointer);

// ---LISTS---

bool addToListOfUnbornProcesses(Process data, ListOfUnbornProcesses *pointer); // функция добавляет данные о процессе в упорядоченном виде (по возрастанию времени появления)
void onHeadOfUnbornProcessesList(Process *process, ListOfUnbornProcesses pointer);
void deleteFromListOfUnbornProcesses(ListOfUnbornProcesses *pointer);

bool addToListOfRunnedParts(RunnedProcess data, ListOfRunnedPartsOfProcesses *pointer);
void clearTheListOfRunnedProcesses(ListOfRunnedPartsOfProcesses *pointer);

#endif // RR_H_INCLUDED
