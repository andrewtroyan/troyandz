#ifndef DETAILS_H_INCLUDED
#define DETAILS_H_INCLUDED

#include <stdlib.h>

typedef struct Philosopher_
{
    int *data;
    int *rightFork, *leftFork;
    int *forkInRightHand, *forkInLeftHand;
} Philosopher;

int takeForks(Philosopher *philosopher);
int putForks(Philosopher *philosopher);
int startToEat(Philosopher *philosopher);
int eatingInProccess(Philosopher *philosopher);
int stopToEat(Philosopher *philosopher);

#endif // DETAILS_H_INCLUDED
