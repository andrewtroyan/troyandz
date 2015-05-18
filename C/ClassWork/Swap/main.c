#include "details.h"

int main()
{
// Инициализация и подготовка оперативной памяти.

    RAM physMem;

    physMem.table = (pageInfo *)malloc((PMSIZE + VMSIZE) * sizeof(pageInfo));
    if(!(physMem.table))
    {
        fprintf(stderr, "Access memory error.\n");
        exit(1);
    }

    physMem.arrayOfPages = (int *)malloc(PMSIZE * sizeof(int));
    if(!(physMem.arrayOfPages))
    {
        fprintf(stderr, "Access memory error.\n");
        free(physMem.table);
        exit(1);
    }

    for(int i = 0; i < PMSIZE; ++i) //иницилизация страниц в оперативной памяти
        physMem.arrayOfPages[i] = 0;

// Инициализация виртуальной памяти

    VM virtMem;

    virtMem.arrayOfPages = (int *)malloc(VMSIZE * sizeof(int));
    if(!(virtMem.arrayOfPages))
    {
        fprintf(stderr, "Access memory error.\n");
        free(physMem.arrayOfPages);
        free(physMem.table);
        exit(1);
    }

    for(int i = 0; i < VMSIZE; ++i) //инициализация страниц в виртуальной памяти
        virtMem.arrayOfPages[i] = 0;

// Инцииализация таблицы в оперативной памяти

    for(int i = 0; i < PMSIZE; ++i)
    {
        physMem.table[i].address = &(physMem.arrayOfPages[i]);
        physMem.table[i].flagOfTime = 0;
        physMem.table[i].where = phys;
    }

    for(int i = PMSIZE; i < VMSIZE; ++i)
    {
        physMem.table[i].address = &(virtMem.arrayOfPages[i - PMSIZE]);
        physMem.table[i].flagOfTime = 0;
        physMem.table[i].where = virt;
    }

// -----

    //работа процессора с функцией getPage

// -----

    free(virtMem.arrayOfPages);
    free(physMem.arrayOfPages);
    free(physMem.table);
    return 0;
}
