#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h> //планировщик задач (для многопроцессорности)
#include <pthread.h> //для многопоточности (в линковщике прописать pthread)

/*
int main()
{
    int i = 0;
    for(; i < 10; ++i)
        printf("%d\n", i);
    fork(); //раздваивает программу (на процессы)
    for(; i < 50; ++i)
    {
        printf("%d\n", i);
        sched_yield(); //разбивает процесс на куски
    }
    return 0;
}
*/
/*
int main()
{
    fork();
    main();
    return 0;
}*/

void *run(void *args);
void *runTwo(void *arg);

int main(int argc, char **argv)
{
    //У потоков РАЗДЕЛЯЕМАЯ память

    //int pthread_create(pthread_t *tid, void *attributes, void *(*threadFunc)(void *), void *arg);
    //tid - индентификатор нового потока
    //attributes - служит для указания аттрибутов потоков (0 - по умолчанию)
    //threadFunc - функция для работы с потоком
    //arg - аргументы потока (0, если не нужно указывать)

/*
    pthread_t tid;
    int arg, result; //result - return code

    if(argc < 2)
    {
        fprintf(stderr, "Too few arguments\n");
        return 1;
    }

    arg = atoi(argv[1]);
    result = pthread_create(&tid, NULL, &run, &arg);
    if(result)
    {
        fprintf(stderr, "Error!\n");
        return 1;
    }

    fprintf(stdout, "Goodbye world!\n");
    while(1);

    //stdout сбрасывается реже, чем stderr
*/


    pthread_t tid1, tid2;
    int arg = 0;

    fprintf(stdout, "Hello world!\n");

    pthread_create(&tid1, NULL, &runTwo, &arg);
    pthread_create(&tid2, NULL, &runTwo, &arg);

    //int pthread_join (pthread_t tid, void **data);
    //void **data - указатель на данные, которые возвращает функция

    pthread_join(tid1, NULL); //вместо while(1);
    pthread_join(tid2, NULL);

    fprintf(stdout, "Goodbye world!\n");

    return 0;
}

void *run(void *args)
{
    int a = *(int *)args;

    sleep(2);
    fprintf(stdout, "Hello world! %d\n", a);

    return NULL;
}

void *runTwo(void *arg)
{
    for(int i = 0; i < 50; ++i)
    {
        fprintf(stderr, "%d\n", i);
        sched_yield();
        //usleep(1);
    }
    return NULL;
}

//Совет: всегда блокировать весь набор мютексов и в обратном порядке разблокировать (стек).
