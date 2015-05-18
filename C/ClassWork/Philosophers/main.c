#include "details.h"

int main()
{
    Philosopher philosophers[5];
    int *forks[5];

    //расставляем вилки между философами:
    philosophers[0].leftFork = forks[0];
    philosophers[1].rightFork = forks[0];

    philosophers[1].leftFork = forks[1];
    philosophers[2].rightFork = forks[1];

    philosophers[2].leftFork = forks[2];
    philosophers[3].rightFork = forks[2];

    philosophers[3].leftFork = forks[3];
    philosophers[4].rightFork = forks[3];

    philosophers[4].leftFork = forks[4];
    philosophers[0].rightFork = forks[4];

    //алгоритм взаимодействия
    int i = -1;
    int time = 0;

    while(1)
    {
        ++time;
        i = (i + 1) % 5;
        if(time % 5)
            for(int i = 0; i < 5; ++i)
                if(!eatingInProccess(&(philosophers[i])))
                    stopToEat(&(philosophers[i]));

        for(int j = 0, k = i; j < 5; ++j, k = (k + 1) % 5)
        {
            if(startToEat(&(philosophers[k])))
                putForks(&(philosophers[k]));
        }
    }
}


