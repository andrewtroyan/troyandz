#ifndef DETAILS_H_INCLUDED
#define DETAILS_H_INCLUDED

#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include "ncursesDetails.h"

#define MESSAGE_LENGTH 512
#define NAME_LENGTH 32

typedef enum runState_ {run, stop, sig} runState; //создаем тип для кода-индикатора

runState runCode; //наш код-индикатор выполнения программы

typedef struct SocketInfo_ //структура, которую мы передаем по сети
{
    char name[NAME_LENGTH], message[MESSAGE_LENGTH];
    int amountOfOnline;
} SocketInfo;

typedef struct ThreadInfo_ //структура, которую мы передаем потоку
{
    WINDOW **listOfWindows;
    int socket;
    char name[NAME_LENGTH];
} ThreadInfo;

int setWindows(WINDOW ***wins, int rows, int cols); //создает ncurses окна
void deleteWindows(WINDOW ***wins); //удаляет ncurses окна

void *readFromServer(void *arg); //функция потока, которая будет находиться в режиме чтения

void sigHandler(int arg); //функция обработки прерывания (меняет код-индикатор)
int setSigAction(void *arg, void (*func)(int arg)); //заполняет структуру по обработке прерываний

void setSocketInfo(SocketInfo *info, char *name, char *message, int amountOfOnline); //заполняет сетевую структуру
void setThrInfo(ThreadInfo *info, WINDOW **wins, int socket, char *name); //заполняет поточную структуру
void setAddr(void *addrStruct, short sinFamily, int sinPort, char *ip); //заполняет структуру адресного пространства (для сокета)

int setSocket(int *clientSocket); //создает сокет и делает его неблокирующим
int connectSocket(int *clientSocket, void *peer); //коннектит сокет с сервером

#endif // DETAILS_H_INCLUDED
