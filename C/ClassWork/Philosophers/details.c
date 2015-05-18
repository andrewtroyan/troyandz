#include "details.h"

int takeForks(Philosopher *philosopher)
{
    if(philosopher->rightFork)
    {
        philosopher->forkInRightHand = philosopher->rightFork;
        philosopher->rightFork = NULL;
    }
    if(philosopher->leftFork)
    {
        philosopher->forkInLeftHand = philosopher->leftFork;
        philosopher->leftFork = NULL;
    }

    if(philosopher->forkInRightHand && philosopher->forkInLeftHand)
        return 2;
    else if(philosopher->forkInRightHand || philosopher->forkInLeftHand)
        return 1;
    else
        return 0;
}

int putForks(Philosopher *philosopher)
{
    if(philosopher->forkInLeftHand)
    {
        philosopher->leftFork = philosopher->forkInLeftHand;
        philosopher->forkInLeftHand = NULL;
    }
    if(philosopher->forkInRightHand)
    {
        philosopher->rightFork = philosopher->forkInRightHand;
        philosopher->forkInRightHand = NULL;
    }
    return 0;
}

int startToEat(Philosopher *philosopher)
{
    int amountOfForks = takeForks(philosopher);
    if(amountOfForks == 2)
        return 0;
    else
        return 1;
}

int eatingInProccess(Philosopher *philosopher) //проверка, ест ли сейчас философ
{
    if(philosopher->forkInLeftHand && philosopher->forkInRightHand)
        return 0;
    else
        return 1;
}

int stopToEat(Philosopher *philosopher)
{
    putForks(philosopher);
    return 0;
}
