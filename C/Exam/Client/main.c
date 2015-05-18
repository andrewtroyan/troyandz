#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>

#include "details.h"

#define PORT 7600

int main()
{
    char ip[16], name[NAME_LENGTH], message[MESSAGE_LENGTH];

    printf("Enter the server IP: ");
    fgets(ip, sizeof(ip), stdin);

    do
    {
        printf("Enter your name: ");
        fgets(name, NAME_LENGTH, stdin);
        name[strlen(name) - 1] = '\0';
    }
    while(!strlen(name));

    SocketInfo infoToSend, infoToGet;
    setSocketInfo(&infoToSend, name, "--add", 0); //"--add" - команда, которую мы посылаем серверу с требованием добавить в его список клиентов и зайти в чат

    struct sockaddr_in peer; //наша структура адресного пространства (для сокета)
    setAddr((void *)&peer, AF_INET, PORT, ip); //заполняем ее

    int clientSocket;

    while(1)
    {
        if(setSocket(&clientSocket))
            return 1;

        if(connectSocket(&clientSocket, (void *)&peer))
            return 1;
//фуункции write и read вводим в цикл while, потому что наш сокет является неблокирующий, а нам нужно наверняка
//отправить или прочитать сообщение
        while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0); //пишем команду на добавление ("--add")

        while(read(clientSocket, &infoToGet, sizeof(infoToGet)) <= 0); //читаем ответ сервера

        if(!strcmp(infoToGet.message, "--denied")) //в том случае, когда сервер отказал в доступе
        {
            printf("Accept denied.\n");
            do
            {
                printf("Enter another name: "); //заново набираем имя
                fgets(name, NAME_LENGTH, stdin);
                name[strlen(name) - 1] = '\0';
            }
            while(!strlen(name));
            strcpy(infoToSend.name, name);
            close(clientSocket);
            continue; //проходим наш цикл заново
        }
        else if(!strcmp(infoToGet.message, "--accepted")) //если сервер принял запрос
            break; //выходим из цикла
        else if(!strcmp(infoToGet.message, "--error")) //другая ошибка (неизвестно)
        {
            fprintf(stderr, "Failed to access.\n");
            close(clientSocket);
            return 1;
        }
    }

    struct winsize size;
    ioctl(1, TIOCGWINSZ, (char *) &size); //заносим в структуру size размеры нашего терминала

    WINDOW **wins = NULL;
    if(setWindows(&wins, size.ws_row, size.ws_col)) //создаем окна согласно полученным размерам
    {
        close(clientSocket);
        return 1;
    }

    ThreadInfo info; //создаем поточную структуру
    setThrInfo(&info, wins, clientSocket, name); //заполняем ее

    runCode = run; //устанавливаем наш код-индикатор

    struct sigaction act; //создаем структуру по обработке прерываний
//Будем обрабатывать прерывания для того, чтобы корректно завершить работу с сервером, если приложение-клиент внезапно
//неправильным (непредвиденным) способом завершило работу.
    if(setSigAction((void *)&act, sigHandler)) //заполняет структуру
    {
        close(clientSocket);
        deleteWindows(&wins);
        return 1;
    }

    pthread_t thread;
    pthread_create(&thread, NULL, &readFromServer, &info); //создаем поток, который будет постоянно находиться в режиме чтения

    while(runCode == run) //пока наш код-индикатор находится в стостоянии работы
    {
        wrefresh(wins[3]);
        curs_set(1);
        wgetnstr(wins[3], message, sizeof(message)); //пользователь вводит сообщение
        wclear(wins[3]);

        strcpy(infoToSend.message, message); //копируем наше сообщение в структуру, которую будем передавать по сети

        while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0);

        if(!strcmp(message, "--exit")) //если пользователь сам захотел выйти из чата
            runCode = stop;
    }

    pthread_cancel(thread); //завершаем поток чтения

    if(runCode == sig) //если же сработало прерывание (работа завершилась неправильно)
    {
        strcpy(infoToSend.message, "--exit"); //мы посылаем обычное сообщение серверу для окончания работы
        while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0);
        close(clientSocket);
        deleteWindows(&wins);
        fprintf(stderr, "Error occured.\n");
        return 1; //выходим с ошибкой
    }
    else if(runCode == stop) //если же клиент сам завершил работу должным образом
    {
        close(clientSocket);
        deleteWindows(&wins);
    }

    return 0; //выходим без ошибки
}
