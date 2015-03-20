#include "FCFS.h"

int main()
{
    FILE *filepoint;

    filepoint = fopen("Processes.txt", "r");
    if(filepoint == NULL)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }

// -----

    int amountOfProcesses;
    fscanf(filepoint, "%d\n", &amountOfProcesses); // считываем кол-во процессов

// -----

    ListOfUnbornProcesses unbornProcesses = NULL;

    Process temp;
    for(int i = 0; i < amountOfProcesses; ++i)
    {
        fscanf(filepoint, "%d %d %d\n", &temp.identifier, &temp.comingTime, &temp.runningTime);
        while(!addToListOfUnbornProcesses(temp, &unbornProcesses)) {} // заносим процессы в список в отсортированном виде (по возрастанию времени рождения)
    }

// -----

    int workingTimeOfCPU = 0;
    Queue processesToRun;
    initializeQueue(&processesToRun);
    ListOfFinishedProcesses finishedProcesses;
    initializeListOfFinishedProcesses(&finishedProcesses);
    FinishedProcess tempFinished;

    while(amountOfFinishedProcesses(finishedProcesses) < amountOfProcesses)
    {
        while(unbornProcesses && workingTimeOfCPU >= unbornProcesses->process.comingTime) // заносим рожденные процессы в очередь
        {
            onHeadOfUnbornProcessesList(&temp, unbornProcesses);
            deleteFromListOfUnbornProcesses(&unbornProcesses);
            while (!addToQueue(temp, &processesToRun)) {}
        }

        if(!isQueueEmpty(processesToRun)) // выносим процессы из очереди на выполнение
        {
            onHeadOfQueue(&temp, processesToRun);
            popFromQueue(&processesToRun);
            tempFinished.identifier = temp.identifier;
            tempFinished.waitingTime = workingTimeOfCPU - temp.comingTime;
            tempFinished.wholeRunningTime = tempFinished.waitingTime + temp.runningTime;
            workingTimeOfCPU += temp.runningTime;
            while (!addToListOfFinishedProcesses(tempFinished, &finishedProcesses)) {}
        }
        else
        {
            ++workingTimeOfCPU;
        }
    }

// -----

    ListOfFinishedProcesses test = finishedProcesses;
    printf("ID    Waiting time    CPU burst\n");
    while(test.node)
    {
        printf("%-5d %-15d %-17d\n", test.node->process.identifier, test.node->process.waitingTime, test.node->process.wholeRunningTime);
        test.node = test.node->link;
    }
    printf("\nWhole working time of CPU: %d quanta.\n", workingTimeOfCPU);

// -----

    fclose(filepoint);
    clearTheListOfFinishedProcesses(&finishedProcesses);
    return 0;
}
