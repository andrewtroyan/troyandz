#include "details.h"

int toSwap(int indexToChange, RAM *physMem, VM *virtMem)
{
    int maxTimeIndex = 0;

    for(int i = maxTimeIndex + 1; i < PMSIZE; ++i) //находим из списка страниц оперативной памяти ту, у которой самый большой flagOfTime
        if(physMem->table[i].flagOfTime > physMem->table[maxTimeIndex].flagOfTime)
            maxTimeIndex = i;

    int *temp = physMem->table[maxTimeIndex].address; //меняем адреса в таблице
    physMem->table[maxTimeIndex].address = physMem->table[indexToChange].address;
    physMem->table[indexToChange].address = temp;

    int tempData = physMem->arrayOfPages[maxTimeIndex]; //меняем сами страницы
    physMem->arrayOfPages[maxTimeIndex] = virtMem->arrayOfPages[indexToChange - PMSIZE];
    virtMem->arrayOfPages[indexToChange - PMSIZE] = tempData;

    physMem->table[maxTimeIndex].flagOfTime = 0; //обнуляем flagOfTime

    return maxTimeIndex;
}

int *getPage(int *inputAddress, RAM *physMem, VM *virtMem)
{
    int index = 0;
    while(physMem->table[index].address != inputAddress)
        ++index;

    if(physMem->table[index].where == phys)
    {
        physMem->table[index].flagOfTime = 0;

        for(int i = 0; i < PMSIZE; ++i) //добавляем по единице времени ко всем страницам в оперативной памяти
            if(i != index)              //кроме той, которую запрашивает процессор (ее время обнуляем)
                ++(physMem->table[i].flagOfTime);

        return physMem->table[index].address;
    }
    else if(physMem->table[index].where == virt)
    {
        index = toSwap(index, physMem, virtMem); //делаем swap

        for(int i = 0; i < PMSIZE; ++i) //добавляем по единице времени ко всем страницам в оперативной памяти
            if(i != index)              //кроме той, которую запрашивает процессор (ее время обнуляем)
                ++(physMem->table[i].flagOfTime);
    }
    return NULL;
}
