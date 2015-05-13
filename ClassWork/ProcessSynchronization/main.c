#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>
#include <sched.h>

int treatSig = 1;

void handler(int snum) //функция-обработчик
{
    treatSig = 0;
}

int main()
{
    int pf[2];  //создаем канал (pipe)
    if(pipe(pf) == -1)
    {
        fprintf(stderr, "Can't create a pipe.\n");
        return 1;
    }

    pid_t p1 = fork();
    if(p1 == -1)
    {
        fprintf(stderr, "Can't create P1 process.\n");
        return 1;
    }
    else if(!p1) //дочерний процесс
    {
        pid_t p2 = fork();
        if(p2 == -1)
        {
            fprintf(stderr, "Can't create P2 process");
            return 1;
        }
        else if(!p2) //дочерний процесс (родитель - P1)
        {
            struct sigaction act;
            sigemptyset(&act.sa_mask);
            act.sa_handler = &handler;
            act.sa_flags = 0;

            if(sigaction(SIGQUIT, &act, NULL) == -1)
            {
                fprintf(stderr, "Can't settle sigaction.\n");
                return 1;
            }

            char symbol;
            FILE *filepoiner = NULL;
            filepoiner = fopen("An_American_Tragedy.txt", "r");
            close(pf[0]);
            while(treatSig && !feof(filepoiner))
            {
                symbol = fgetc(filepoiner);
                write(pf[1], &symbol, sizeof(symbol));
            }
            fclose(filepoiner);
        }
        else //родительский процесс (P1)
        {
            usleep(15000);
            kill(p2, SIGQUIT);
        }
    }
    else
    {
        waitpid(p1, NULL, 0);
        char symbol;
        close(pf[1]);
        while(read(pf[0], &symbol, sizeof(symbol)) > 0)
            printf("%c", symbol);
    }
    return 0;
}
