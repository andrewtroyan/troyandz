#include <sys/socket.h>
#include <netinet/in.h>

#include "details.h"

int main()
{
    int listenSocket, clientSocket;
    struct sockaddr_in local;
    if(setListenSocket(&listenSocket, (void *)&local))
        return 1;

    runCode = run;

    struct sigaction act;
    if(setSigAction(&act, sigHandler))
    {
        close(listenSocket);
        return 1;
    }

    int epollDescriptor = epoll_create(EPOLL_SIZE); //создаем инструмент, с помощью которго будем обрабатывать дескрипторы (сокеты клиентов)
    struct epoll_event *events = NULL;
    events = (struct epoll_event *)malloc(EPOLL_SIZE * sizeof(struct epoll_event));
    if(!events)
    {
        fprintf(stderr, "Can't create events for epoll.\n");
        close(listenSocket);
        return 1;
    }

    addToEpoll(epollDescriptor, EPOLLIN, listenSocket);

    int amountOfEvents;
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
                        clientSocket = accept(listenSocket, NULL, NULL);

                    if(clientSocket < 0)
                        continue;

                    if(fcntl(clientSocket, F_SETFL, O_NONBLOCK, 1) == -1)
                    {
                        fprintf(stderr, "Failed to set non-block mode.\n");
                        close(clientSocket);
                        continue;
                    }

                    while(read(clientSocket, &infoToGet, sizeof(infoToGet)) <= 0);

                    setSocketInfo(&infoToSend, "\0", "--error", 0);

                    if(!strcmp(infoToGet.message, "--add"))
                    {
                        if(!checkTheLength(infoToGet.name) && !checkTheSame(clientList, infoToGet.name))
                        {
                            addClient(&clientList, infoToGet.name, clientSocket);
                            addToEpoll(epollDescriptor, EPOLLIN | EPOLLOUT, clientSocket);

                            setSocketInfo(&infoToSend, "\0", "--accepted", 0);
                        }
                        else
                            setSocketInfo(&infoToSend, "\0", "--denied", 0);
                    }

                    while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0);

                    setSocketInfo(&infoToSend, "\0", "\0", clientList->amountOfOnline);
                    writeToAllClients(clientList, &infoToSend);
                }
                else if((events[i].events & EPOLLIN) == EPOLLIN)
                {
                    while(read(events[i].data.fd, &infoToGet, sizeof(infoToGet)) <= 0);
                    if(!strcmp(infoToGet.message, "--exit"))
                    {
                        deleteClient(&clientList, events[i].data.fd);

                        if(clientList)
                        {
                            setSocketInfo(&infoToSend, "\0", "\0", clientList->amountOfOnline);
                            writeToAllClients(clientList, &infoToSend);
                        }
                    }
                    else if(strlen(infoToGet.message))
                    {
                        infoToGet.amountOfOnline = clientList->amountOfOnline;

                        writeToAllClients(clientList, &infoToGet);
                    }
                }
            }
        }
    }

    if(runCode == sig)
    {
        setSocketInfo(&infoToSend, "\0", "--exit", 0);
        writeToAllClients(clientList, &infoToSend);
        clearClientList(&clientList);
        close(listenSocket);
        free(events);
        fprintf(stderr, "\nError occured.\n");
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
