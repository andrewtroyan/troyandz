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
            execlp("../Server/bin/Debug/Server", "../Server/bin/Debug/Server", "&", NULL); //этой функцией мы передаем дальнейшее выполнение программе-серверу (в фоновом режиме)
            fprintf(stderr, "Error: execlp.\n");
            return 1;
        }
        else if(!result) //процесс "ребенок"
        {
            system("clear");
            execlp("../Client/bin/Debug/Client", "", NULL); //этой функцией мы передаем дальнейшее выполнение программе-клиенту
            fprintf(stderr, "Error: execlp.\n");
            return 1;
        }
    }
    else if(answer == 'n') //если пользователь отказался хостить программу, то
    {
        printf("Do you want to start server or client? s/c: ");
        scanf(" %c", &answer);
        if(answer == 's')
        {
            execlp("../Server/bin/Debug/Server", "", NULL); //он может запустить либо отдельно сервер,
            fprintf(stderr, "Error: execlp.\n");
            return 1;
        }
        else if(answer == 'c')
        {
            system("clear");
            execlp("../Client/bin/Debug/Client", "", NULL); //либо отдельно клиента
            fprintf(stderr, "Error: execlp.\n");
            return 1;
        }
        else
            return 1;
    }
    else
        return 1;
    return 0;
}
