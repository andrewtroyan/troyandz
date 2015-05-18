#ifndef DETAILS_H_INCLUDED
#define DETAILS_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/epoll.h>

#define MESSAGE_LENGTH 512
#define NAME_LENGTH 32

#define PORT 7600
#define LISTEN_QUEUE 64
#define EPOLL_SIZE 65

typedef enum runState_ {run, sig, noClients} runState;

runState runCode;

typedef struct Client_
{
    char name[NAME_LENGTH];
    int socket, amountOfOnline;
    struct Client_ *previous, *next;
} Client;

typedef struct SocketInfo_
{
    char name[NAME_LENGTH], message[MESSAGE_LENGTH];
    int amountOfOnline;
} SocketInfo;

int setListenSocket(int *listenSocket, void *address);
int addClient(Client **list, char *name, int socket);
int deleteClient(Client **list, int socket);
void clearClientList(Client **list);
int checkTheLength(char *name);
int checkTheSame(Client *list, char *name);
void writeToAllClients(Client *list, SocketInfo *info);
void sigHandler(int arg);
int setSigAction(void *arg, void (*func)(int arg));
void addToEpoll(int epoll, uint32_t events, int descriptor);
void setSocketInfo(SocketInfo *info, char *name, char *message, int amountOfOnline);

#endif // DETAILS_H_INCLUDED
