#ifndef DETAILS_H_INCLUDED
#define DETAILS_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MESSAGE_LENGTH 512
#define NAME_LENGTH 32

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

int addClient(Client **list, char *name, int socket);
int deleteClient(Client **list, int socket);
int checkTheLength(char *name);
int checkTheSame(Client *list, char *name);
void writeToAllClients(Client *list, SocketInfo *info);

#endif // DETAILS_H_INCLUDED
