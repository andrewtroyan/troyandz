#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/epoll.h>

#include "details.h"

#define PORT 7500

int main()
{
    char ip[16], name[NAME_LENGTH];

    printf("Enter the server IP: ");
    fgets(ip, 15, stdin);

    printf("Enter your name: ");
    fgets(name, NAME_LENGTH - 1, stdin);
    name[strlen(name) - 1] = '\0';

    SocketInfo infoToSend, infoToGet;

    strcpy(infoToSend.name, name);
    strcpy(infoToSend.message, "--add");
    infoToSend.amountOfOnline = 0;

    int error = 1, clientSocket;
    struct sockaddr_in peer;

    peer.sin_family = AF_INET;
    peer.sin_port = htons(PORT);
    peer.sin_addr.s_addr = inet_addr(ip);

    while(error)
    {
        clientSocket = socket(AF_INET, SOCK_STREAM, 0); //создаем сокет
        if(clientSocket < 0)
        {
            fprintf(stderr, "socket() error.\n");
            return 1;
        }

        if(fcntl(clientSocket, F_SETFL, O_NONBLOCK, 1) == -1) //делаем этот сокет неблокирующим
        {
            fprintf(stderr, "Failed to set non-block mode.\n");
            close(clientSocket);
            return 1;
        }

        for(int i = 0; i < 1000 && error; ++i)
            error = connect(clientSocket, (struct sockaddr *)&peer, sizeof(peer)); //коннектимся к серверу

        if(error)
        {
            fprintf(stderr, "Can't connect.\n");
            close(clientSocket);
            return 1;
        }

        while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0); //пишем команду на добавление ("--add")

        while(read(clientSocket, &infoToGet, sizeof(infoToGet)) <= 0); //читаем ответ сервера

        if(!strcmp(infoToGet.message, "--denied")) //в том случае, когда сервер отказал в доступе
        {
            printf("Accept denied. Enter another name: ");
            fgets(name, NAME_LENGTH - 1, stdin);
            strcpy(infoToSend.name, name);
            close(clientSocket);
            error = 1;
        }
        else if(!strcmp(infoToGet.message, "--accepted")) //сервер принял
            error = 0;
        else if(!strcmp(infoToGet.message, "--error")) //другая ошибка (неизвестно)
        {
            fprintf(stderr, "Failed to access.\n");
            close(clientSocket);
            return 1;
        }
        else
        {
            fprintf(stderr, "Failed to access.\n");
            close(clientSocket);
            return 1;
        }
    }

    struct winsize size;
    ioctl(1, TIOCGWINSZ, (char *) &size);

    WINDOW **wins = NULL;
    if(setWindows(&wins, size.ws_row, size.ws_col)) //создаем окна
        return 1;

    refresh();
    curs_set(0);
    wprintw(wins[2], "Users online: %d", infoToGet.amountOfOnline);
    wrefresh(wins[2]);
    wrefresh(wins[3]);
    curs_set(1);

    ThreadInfo info;
    info.listOfWindows = wins;
    strcpy(info.name, name);
    info.socket = clientSocket;

    char message[MESSAGE_LENGTH];

    pthread_t thread1;

    pthread_create(&thread1, NULL, &readFromServer, &info); //создаем поток, который будет постоянно находиться в режиме чтения

    while(1)
    {
        wrefresh(wins[3]);
        curs_set(1);
        wgetnstr(wins[3], message, sizeof(message) - 1); //пользователь вводит сообщение
        wclear(wins[3]);

        strcpy(infoToSend.message, message); //копируем наше сообщение в структуру, которую будем передавать по сети

        while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0);

        if(!strcmp(message, "--exit")) //если мы ввели это сообщение
        {
            close(clientSocket); //то закрываем сокет
            deleteWindows(&wins); //закрываем наши ncurses окна
            exit(0); //и выходим без какой-либо ошибки
        }
    }

    return 0;
}
