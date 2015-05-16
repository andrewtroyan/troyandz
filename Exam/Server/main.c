#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#include "details.h"

int main()
{
    int listenSocket;
    struct sockaddr_in local;

    if(setListenSocket(&listenSocket, (void *)&local))
        return 1;

    runCode = run;
    struct sigaction act;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler = &sigHandler;

    if(sigaction(SIGHUP, &act, NULL) == -1 || sigaction(SIGINT, &act, NULL) == -1)
    {
        fprintf (stderr, "sigaction() error.\n");
        close(listenSocket);
        return 1;
    }

    int epollDescriptor = epoll_create(EPOLL_SIZE); //создаем инструмент, с помощью которго будем обрабатывать дескрипторы (сокеты клиентов)
    struct epoll_event event;
    struct epoll_event *events;

    events = (struct epoll_event *)malloc(EPOLL_SIZE * sizeof(struct epoll_event));

    event.events = EPOLLIN | EPOLLPRI | EPOLLERR | EPOLLHUP;
    event.data.fd = listenSocket;
    epoll_ctl(epollDescriptor, EPOLL_CTL_ADD, listenSocket, &event);

    int amountOfEvents, clientSocket;
    struct sockaddr_in clientAddress;
    socklen_t addrSize;

    Client *clientList = NULL;
    SocketInfo infoToGet, infoToSend;

    while(runCode == run)
    {
        amountOfEvents = epoll_wait(epollDescriptor, events, EPOLL_SIZE, 60000);
        if(!amountOfEvents)
            runCode = noClients;
        else if(amountOfEvents > 0)
        {
            for(int i = 0; i < amountOfEvents; ++i)
            {
                if(events[i].data.fd == listenSocket)
                {
                    clientSocket = -1;

                    for(int i = 0; i < 1000 && clientSocket < 0; ++i)
                        clientSocket = accept(listenSocket, (struct sockaddr *)&clientAddress, &addrSize);

                    if(clientSocket < 0)
                    {
                        char ip[16];
                        sprintf(ip, "%d", clientAddress.sin_addr.s_addr);
                        fprintf(stderr, "Failed to accept a client (IP: %s).\n", ip);
                        continue;
                    }

                    if(fcntl(clientSocket, F_SETFL, O_NONBLOCK, 1) == -1)
                    {
                        fprintf(stderr, "Failed to set non-block mode.\n");
                        close(clientSocket);
                        continue;
                    }

                    while(read(clientSocket, &infoToGet, sizeof(infoToGet)) <= 0);

                    memset(infoToSend.name, 0, strlen(infoToSend.name));
                    strcpy(infoToSend.message, "--error");
                    infoToSend.amountOfOnline = 0;

                    if(!strcmp(infoToGet.message, "--add"))
                    {
                        if(!checkTheLength(infoToGet.name) && !checkTheSame(clientList, infoToGet.name))
                        {
                            addClient(&clientList, infoToGet.name, clientSocket);

                            event.events = EPOLLIN | EPOLLOUT | EPOLLHUP;
                            event.data.fd = clientSocket;
                            epoll_ctl(epollDescriptor, EPOLL_CTL_ADD, clientSocket, &event);

                            strcpy(infoToSend.message, "--accepted");
                            infoToSend.amountOfOnline = clientList->amountOfOnline;
                        }
                        else
                            strcpy(infoToSend.message, "--denied");
                    }

                    while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0);

                    memset(infoToSend.name, 0, strlen(infoToSend.name));
                    memset(infoToSend.message, 0, strlen(infoToSend.message));
                    writeToAllClients(clientList, &infoToSend);
                }
                else if((events[i].events & EPOLLIN) == EPOLLIN)
                {
                    while(read(events[i].data.fd, &infoToGet, sizeof(infoToGet)) <= 0);
                    if(!strcmp(infoToGet.message, "--exit"))
                    {
                        deleteClient(&clientList, events[i].data.fd);
                        epoll_ctl(epollDescriptor, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                        close(events[i].data.fd);

                        if(clientList)
                        {
                            memset(infoToSend.name, 0, strlen(infoToSend.name));
                            memset(infoToSend.message, 0, strlen(infoToSend.message));
                            --(infoToSend.amountOfOnline);
                            writeToAllClients(clientList, &infoToSend);
                        }
                    }
                    else if(strlen(infoToGet.message))
                    {
                        int amountOfOnline = clientList->amountOfOnline;
                        infoToGet.amountOfOnline = amountOfOnline;

                        writeToAllClients(clientList, &infoToGet);
                    }
                }
            }
        }
    }

    if(runCode == sig)
    {
        memset(infoToSend.name, 0, strlen(infoToSend.name));
        strcpy(infoToSend.message, "--exit");
        infoToSend.amountOfOnline = 0;
        writeToAllClients(clientList, &infoToSend);
        close(listenSocket);
        clearClientList(&clientList);
        free(events);
        fprintf(stderr, "Error occured.\n");
        return 1;
    }
    else if(runCode == noClients)
    {
        fprintf(stderr, "No clients.\n");
        close(listenSocket);
        free(events);
        return 0;
    }

    return 0;
}
