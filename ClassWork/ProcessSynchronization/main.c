#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

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
            filepoiner = fopen("Voyna_I_Mir_Tom_1.txt", "r");

            while(treatSig && !feof(filepoiner))
            {
                symbol = fgetc(filepoiner);
                write(pf[0], &symbol, sizeof(symbol));
            }

            symbol = '\0';

            write(pf[0], &symbol, sizeof(symbol));
            close(pf[0]);
        }
        else //родительский процесс (P1)
        {
            sleep(500);
            kill(p2, SIGQUIT);
        }
    }
    else
    {
        wait(NULL);
        char symbol;
        read(pf[1], &symbol, sizeof(symbol));
        while(symbol != '\0')
        {
            printf("%c", symbol);
            read(pf[1], &symbol, sizeof(symbol));
        }
        close(pf[1]);
    }
    return 0;
}
