#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/epoll.h>

#include "details.h"

#define PORT 7570

int main()
{
    setlocale(LC_ALL,"ru_RU.UTF-8");

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
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if(clientSocket < 0)
        {
            fprintf(stderr, "socket() error.\n");
            return 1;
        }

        if(fcntl(clientSocket, F_SETFL, O_NONBLOCK, 1) == -1)
        {
            fprintf(stderr, "Failed to set non-block mode.\n");
            close(clientSocket);
            return 1;
        }

        while(connect(clientSocket, (struct sockaddr *)&peer, sizeof(peer)));

        while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0);

        while(read(clientSocket, &infoToGet, sizeof(infoToGet)) <= 0);

        if(!strcmp(infoToGet.message, "--denied"))
        {
            printf("Accept denied. Enter another name: ");
            fgets(name, NAME_LENGTH - 1, stdin);
            strcpy(infoToSend.name, name);
            close(clientSocket);
            error = 1;
        }
        else if(!strcmp(infoToGet.message, "--accepted"))
            error = 0;
        else if(!strcmp(infoToGet.message, "--error"))
        {
            fprintf(stderr, "Failed to access.\n");
            close(clientSocket);
            return 1;
        }
    }

    struct winsize size;
    ioctl(1, TIOCGWINSZ, (char *) &size);

    WINDOW **wins = NULL;
    if(setWindows(&wins, size.ws_row, size.ws_col))
        return 1;

    wprintw(wins[2], "Users online: %d", infoToGet.amountOfOnline);
    wrefresh(wins[2]);

    ThreadInfo info;
    info.listOfWindows = wins;
    strcpy(info.name, name);
    info.socket = clientSocket;

    char message[MESSAGE_LENGTH];

    pthread_t thread1;

    pthread_create(&thread1, NULL, &readFromServer, &info);

    while(1)
    {
        char symbol = wgetch(wins[3]);
        int i = 0;
        while(symbol != '\n' && i < 255)
        {
            wprintw(wins[3], "%c", symbol);
            wrefresh(wins[3]);
            message[i] = symbol;
            symbol = wgetch(wins[3]);
            ++i;
        }
        message[i] = '\0';
        wclear(wins[3]);

        strcpy(infoToSend.message, message);

        while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0);

        if(!strcmp(message, "--exit"))
        {
            close(clientSocket);
            deleteWindows(&wins);
            exit(0);
        }
    }

    return 0;
}
