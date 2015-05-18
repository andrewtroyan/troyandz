#ifndef DETAILS_H_INCLUDED
#define DETAILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define PMSIZE 1024
#define VMSIZE 1536

typedef enum State_ {phys, virt} State; //тип состояний, который определяет, находится страница в оперативной памяти либо в виртуальной

typedef struct pageInfo_ //"строка" таблицы, которая содержит адрес страницы, индикатор нахождения (в ФП или ВП) и флаг времени
{
    int *address;
    State where ;
    int flagOfTime;
} pageInfo;

typedef struct RAM_ //оперативная память, которая представлена массивом страниц в ОЗУ и таблицей, которая описывает страницы
{                   //в оперативной и виртуальной памяти
    int *arrayOfPages; //массив страниц оперативной памяти
    pageInfo *table;   //таблица
} RAM;

typedef struct VM_ //виртуальная память, которая представлена только массивом страниц виртуальной памяти
{
    int *arrayOfPages;
} VM;

int toSwap(int indexToChange, RAM *physMem, VM *virtMem);
int *getPage(int *inputAddress, RAM *physMem, VM *virtMem);

#endif // DETAILS_H_INCLUDED
