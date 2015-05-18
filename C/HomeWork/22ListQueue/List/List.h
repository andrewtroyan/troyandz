#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSTR 30

typedef struct Data_     // тип для данных
{
    char name[MAXSTR];
    double area;
} Data;

typedef struct Node_     // тип узла
{
    Data data;
    struct Node_ * link;
} Node;

typedef Node * List;    // тип для указателя на узел

void initializeList(List *pointer); // создает начало списка
bool addToList(Data data, List *pointer); //добавляет данные в конец списка (или создает первый узел, если список пуст)
void clearTheList(List *pointer); // очищает список
bool isEmpty(const List pointer); //проверяет, пуст ли список
bool isFull(const List pointer); //проверяет, можно ли создать еще один узел
int amountOfNodes(const List pointer); //подсчитывает и возвращает количество узлов
void workOnNodes(const List pointer, void (*function)(Data data)); //обрабатывает каждый узел функцией function

#endif // LIST_H_INCLUDED
