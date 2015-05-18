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

typedef enum runState_ {run, sig, noClients} runState; //создаем тип для кода-индикатора

runState runCode; //наш код-индикатор выполнения программы

typedef struct Client_ //наша структура для одного клиента (будем создавать динамическую структуру данных клиентов)
{
    char name[NAME_LENGTH];
    int socket, amountOfOnline;
    struct Client_ *previous, *next;
} Client;

typedef struct SocketInfo_ //структура, которую будем передавать по сети
{
    char name[NAME_LENGTH], message[MESSAGE_LENGTH];
    int amountOfOnline;
} SocketInfo;

int setListenSocket(int *listenSocket, void *address); //настраивает прослушивающий сокет

int addClient(Client **list, char *name, int socket); //добавляет клиента в список
int deleteClient(Client **list, int socket); //удаляет клиента из списка
void clearClientList(Client **list); //очищает список
void writeToAllClients(Client *list, SocketInfo *info); //рассылает сообщение всем клиентам (если они есть)

int checkTheLength(char *name); //проверяет длину имени
int checkTheSame(Client *list, char *name); //проверяет, нет ли в нашем списке клиента с таким же именем

void sigHandler(int arg); //функция-обработчик сигнала (меняет код-индикатор)
int setSigAction(void *arg, void (*func)(int arg)); //заполняет структуру для обработки сигнала

void addToEpoll(int epoll, uint32_t events, int descriptor); //добавляет нового члена в наш инструмент epoll

void setSocketInfo(SocketInfo *info, char *name, char *message, int amountOfOnline); //заполняет структуру данными для передачи по сети

#endif // DETAILS_H_INCLUDED
