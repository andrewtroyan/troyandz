#include "RR.h"

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

    int workingTimeOfCPU = 0, periodOfTimeToChange;
    Queue processesToRun;
    initializeQueue(&processesToRun);
    ListOfRunnedPartsOfProcesses runnedProcesses = NULL;
    RunnedProcess tempRunned;

    printf("Enter the period of time to change a process for another one: ");
    scanf("%d", &periodOfTimeToChange);

    for(int amount = 0; amount < amountOfProcesses; )
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
            tempRunned.identifier = temp.identifier;
            tempRunned.waitingTime = workingTimeOfCPU - temp.comingTime;
            if(temp.runningTime > periodOfTimeToChange)
            {
                tempRunned.runningTime = periodOfTimeToChange;
                workingTimeOfCPU += periodOfTimeToChange;
                temp.comingTime = workingTimeOfCPU;
                temp.runningTime -= periodOfTimeToChange;
                addToQueue(temp, &processesToRun);
            }
            else
            {
                tempRunned.runningTime = temp.runningTime;
                workingTimeOfCPU += temp.runningTime;
                ++amount;
            }
            while (!addToListOfRunnedParts(tempRunned, &runnedProcesses)) {}
        }
        else
        {
            ++workingTimeOfCPU;
        }
    }

// -----

    ListOfRunnedPartsOfProcesses test = runnedProcesses;
    printf("ID    Waiting time    CPU burst\n");
    while(test)
    {
        printf("%-5d %-15d %-17d\n", test->runnedProcess.identifier, test->runnedProcess.waitingTime, test->runnedProcess.runningTime);
        test = test->link;
    }
    printf("\nWhole working time of CPU: %d quanta.\n", workingTimeOfCPU);

// -----

    fclose(filepoint);
    clearTheListOfRunnedProcesses(&runnedProcesses);
    return 0;
}
