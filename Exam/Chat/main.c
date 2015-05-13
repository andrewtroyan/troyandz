#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
    char answer;
    printf("Welcome to chat! Do you want to host this app? y/n: ");
    scanf(" %c", &answer);
    if(answer == 'y')
    {
        pid_t result = fork(); //"раздваиваю" программу
        if(result > 0) //процесс "родитель"
        {
            execl("../Server/bin/Debug/Server", "&", NULL); //этой функцией мы передаем дальнейшее выполнение программе-серверу
            fprintf(stderr, "Error: execv.\n");
            return 1;
        }
        else if(!result) //процесс "ребенок"
        {
            system("clear");
            execl("../Client/bin/Debug/Client", NULL); //этой функцией мы передаем дальнейшее выполнение программе-клиенту
            fprintf(stderr, "Error: execv.\n");
            return 1;
        }
    }
    else if(answer == 'n')
    {
        printf("Do you want to start server or client? s/c: ");
        scanf(" %c", &answer);
        if(answer == 's')
        {
            execl("../Server/bin/Debug/Server", "&", NULL);
            fprintf(stderr, "Error: execv.\n");
            return 1;
        }
        else if(answer == 'c')
        {
            system("clear");
            execl("../Client/bin/Debug/Client", NULL);
            fprintf(stderr, "Error: execv.\n");
            return 1;
        }
        else
            return 1;
    }
    else
        return 1;
    return 0;
}
