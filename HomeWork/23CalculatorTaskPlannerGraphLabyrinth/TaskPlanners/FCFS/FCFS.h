#ifndef FCFS_H_INCLUDED
#define FCFS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---

typedef struct Process_
{
    int identifier, comingTime, runningTime;
} Process;

typedef struct FinishedProcess_
{
    int identifier, waitingTime, wholeRunningTime;
} FinishedProcess;

// ---

typedef struct RunningNode_
{
    Process process;
    struct RunningNode_ *link;
} RunningNode;

typedef struct FinishedNode_
{
    FinishedProcess process;
    struct FinishedNode_ *link;
} FinishedNode;

// ---

typedef struct Queue_
{
    RunningNode *head, *tail;
} Queue;

typedef RunningNode * ListOfUnbornProcesses;

typedef struct ListOfFinishedProcesses_
{
    FinishedNode *node;
    int amountOfFinishedProcesses;
} ListOfFinishedProcesses;

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

void initializeListOfFinishedProcesses(ListOfFinishedProcesses *pointer);
bool addToListOfFinishedProcesses(FinishedProcess data, ListOfFinishedProcesses *pointer);
void clearTheListOfFinishedProcesses(ListOfFinishedProcesses *pointer);
int amountOfFinishedProcesses(ListOfFinishedProcesses pointer);

#endif // FCFS_H_INCLUDED
