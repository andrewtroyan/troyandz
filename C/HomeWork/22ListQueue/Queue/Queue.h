#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSTR 30

typedef struct Data_
{
    char name[MAXSTR];
    double area;
} Data;

typedef struct Node_
{
    Data data;
    struct Node_ *link;
} Node;

typedef struct Queue_
{
    Node *head, *tail;
} Queue;

void initializeQueue(Queue *pointer); // инициализирует очередь
bool addToQueue(Data data, Queue *pointer); // добавляет в очередь
void removeFromQueue(Queue *pointer); // удаляет из очереди
int amountOfNodesInQueue(const Queue pointer); // подсчитывает и возвращает количество узлов
bool isEmpty(const Queue pointer); // проверяет, пуста ли очередь
bool isFull(const Queue pointer); // проверяет, можно ли в очередь добавить еще один узел
void clearQueue(Queue *pointer); // очищает очередь
void workOnNodes(const Queue pointer, void (*function)(Data)); // обрабатывает каждый узел функцией function

#endif // QUEUE_H_INCLUDED
