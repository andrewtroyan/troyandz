#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include "details.h"

#define PORT 7570
#define LISTEN_QUEUE 64
#define EPOLL_SIZE 65

int main()
{
    int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(listenSocket < 0)
    {
        fprintf(stderr, "Error: socket.\n");
        return 1;
    }

    if(fcntl(listenSocket, F_SETFL, O_NONBLOCK, 1) == -1)
    {
        fprintf(stderr, "Failed to set non-block mode.\n");
        close(listenSocket);
        return 1;
    }

    int error;
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(PORT);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    error = bind(listenSocket, (const struct sockaddr *)&local, sizeof(local));
    if(error)
    {
        fprintf(stderr, "Error: bind.\n");
        close(listenSocket);
        return 1;
    }

    error = listen(listenSocket, LISTEN_QUEUE);
    if(error)
    {
        fprintf(stderr, "Error: listen.\n");
        close(listenSocket);
        return 1;
    }

    int epollDescriptor = epoll_create(EPOLL_SIZE);
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

    while(1)
    {
        amountOfEvents = epoll_wait(epollDescriptor, events, EPOLL_SIZE, -1);
        if(amountOfEvents == -1)
        {
            fprintf(stderr, "Error: epoll_wait.\n");
            close(listenSocket);
            return 1;
        }

        for(int i = 0; i < amountOfEvents; ++i)
        {
            if(events[i].data.fd == listenSocket)
            {
                clientSocket = accept(listenSocket, (struct sockaddr *)&clientAddress, &addrSize);
                if(clientSocket < 0)
                {
                    char ip[16];
                    sprintf(ip, "%d", clientAddress.sin_addr.s_addr);
                    fprintf(stderr, "Failed to accept a client (IP: %s).\n", ip);
                }

                if(fcntl(clientSocket, F_SETFL, O_NONBLOCK, 1) == -1)
                {
                    fprintf(stderr, "Failed to set non-block mode.\n");
                    close(clientSocket);
                    return 1;
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

                        event.events = EPOLLIN | EPOLLOUT;
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
            else
            {
                if((events[i].events & EPOLLIN) == EPOLLIN)
                {
                    while(read(events[i].data.fd, &infoToGet, sizeof(infoToGet)) <= 0);
                    if(!strcmp(infoToGet.message, "--exit"))
                    {
                        deleteClient(&clientList, events[i].data.fd);
                        epoll_ctl(epollDescriptor, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                        close(events[i].data.fd);

                        if(!clientList)
                            infoToSend.amountOfOnline = 0;

                        memset(infoToSend.name, 0, strlen(infoToSend.name));
                        memset(infoToSend.message, 0, strlen(infoToSend.message));
                        writeToAllClients(clientList, &infoToSend);
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

    free(events);

    return 0;
}
