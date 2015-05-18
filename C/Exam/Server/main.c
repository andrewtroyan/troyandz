#include <sys/socket.h>
#include <netinet/in.h>

#include "details.h"

int main()
{
    int listenSocket, clientSocket;
    struct sockaddr_in local; //создаем структуру адресного пространства (для сокета)
    if(setListenSocket(&listenSocket, (void *)&local)) //настраиваем слушающий сокет
        return 1;

    runCode = run; //устанавливаем код-индикатор

    struct sigaction act; //создаем структуру для обработки сигнала
    if(setSigAction(&act, sigHandler)) //заполняем ее
    {
        close(listenSocket);
        return 1;
    }

//Создаем инструмент epoll. Этот инструмент "отлавливает" сигналы, которые посылают ему клиенты и обрабатывает их.
//Благодаря этому инструменту у нас есть возможность сделать сервер однопоточным.
    int epollDescriptor = epoll_create(EPOLL_SIZE); //устанаваливаем количество членов, которые может обрабатывать epoll
    struct epoll_event *events = NULL; //создаем массив структур для обрабтки сигналов
    events = (struct epoll_event *)malloc(EPOLL_SIZE * sizeof(struct epoll_event));
    if(!events)
    {
        fprintf(stderr, "Can't create events for epoll.\n");
        close(listenSocket);
        return 1;
    }

    addToEpoll(epollDescriptor, EPOLLIN, listenSocket); //добавляем первый член в наш epoll (наш слушающий сокет)

    int amountOfEvents;
    Client *clientList = NULL;
    SocketInfo infoToGet, infoToSend;

    while(runCode == run) //пока наш код-индикатор находится в состоянии работы
    {
        amountOfEvents = epoll_wait(epollDescriptor, events, EPOLL_SIZE, 60000); //ждем появления сигналов.
        //Если сигналов не будет в течении 1 минуты, сервер отключится.
        if(!amountOfEvents)
            runCode = noClients;
        else if(amountOfEvents > 0)
        {
            for(int i = 0; i < amountOfEvents; ++i) //пробегаемся по нашим сигналам
            {
                if(events[i].data.fd == listenSocket) //если "просигналил" наш слушающий сокет, то к нему хотят подключиться
                {
                    clientSocket = -1;
                    //Вводим функцию в цикл, так как наш сокет является неблокирующий, а нам нужно, чтобы функция выполнилась наверняка
                    for(int i = 0; i < 1000 && clientSocket < 0; ++i)
                        clientSocket = accept(listenSocket, NULL, NULL);
                    if(clientSocket < 0) //если же все-таки не удалось принять клиента, пробегаемся по сигналам дальше
                        continue;

                    if(fcntl(clientSocket, F_SETFL, O_NONBLOCK, 1) == -1) //устанавливаем подключенный сокет в неблокирующий режим
                    {
                        fprintf(stderr, "Failed to set non-block mode.\n");
                        close(clientSocket);
                        continue;
                    }

                    while(read(clientSocket, &infoToGet, sizeof(infoToGet)) <= 0); //читаем сообщение от клиента

                    setSocketInfo(&infoToSend, "\0", "--error", 0); //заранее подгатавливаем структуру

                    if(!strcmp(infoToGet.message, "--add")) //если клиент просит добавить его в наш список клиентов и войти в чат
                    {
                        if(!checkTheLength(infoToGet.name) && !checkTheSame(clientList, infoToGet.name)) //проверяем его
                        {
                            addClient(&clientList, infoToGet.name, clientSocket); //если все ок, добавляе его
                            addToEpoll(epollDescriptor, EPOLLIN | EPOLLOUT, clientSocket); //а также добавляем в epoll

                            setSocketInfo(&infoToSend, "\0", "--accepted", 0); //переписываем нашу структуру для отправки
                        }
                        else
                            setSocketInfo(&infoToSend, "\0", "--denied", 0); //иначе готовим сообщение об отказе
                    }

                    while(write(clientSocket, &infoToSend, sizeof(infoToSend)) <= 0); //отправляем ответ

                    setSocketInfo(&infoToSend, "\0", "\0", clientList->amountOfOnline); //оповещаем клиентов (если они есть) о количестве онлайн-пользователей
                    writeToAllClients(clientList, &infoToSend);
                }
                else if((events[i].events & EPOLLIN) == EPOLLIN) //если какой-то клиент нам прислал сообщение
                {
                    while(read(events[i].data.fd, &infoToGet, sizeof(infoToGet)) <= 0); //читаем его
                    if(!strcmp(infoToGet.message, "--exit")) //если клиент завершает работу
                    {
                        deleteClient(&clientList, events[i].data.fd); //удаляем его из списка клиентов (из epoll он удалится автоматически, так как мы закроем его сокет)
                        if(clientList) //если у нас остались клиенты
                        {
                            setSocketInfo(&infoToSend, "\0", "\0", clientList->amountOfOnline); //то оповещаем о новом количестве онлайн-пользователей (-1)
                            writeToAllClients(clientList, &infoToSend);
                        }
                    }
                    else if(strlen(infoToGet.message)) //если же это обычное сообщение от клиента
                    {
                        infoToGet.amountOfOnline = clientList->amountOfOnline;
                        writeToAllClients(clientList, &infoToGet); //то рассылаем это сообщение всем клиентам, включая того, который прислал это сообщение
                    }
                }
            }
        }
    }

    if(runCode == sig) //если сработало прерывание (сервер завершает работу неправильно и непредвиденно)
    {
        setSocketInfo(&infoToSend, "\0", "--exit", 0); //оповещаем всех клиентов (если они есть) о завершении работы сервера
        writeToAllClients(clientList, &infoToSend);
        clearClientList(&clientList); //очищаем список клиентов (если он не пустой), из epoll они удалятся автоматически
        close(listenSocket); //закрываем слущающий сокет
        free(events); //освобождаем память, выделенную под массив структур для обработки сигналов
        fprintf(stderr, "\nError occured.\n"); //пишем сообщение ошибки
        return 1; //выходим с ошибкой
    }
    else if(runCode == noClients) //если же не было клиентов в течении 1 минуты
    {
        fprintf(stderr, "No clients.\n"); //пишем сообщение об этом
        close(listenSocket); //закрываем слущающий сокет
        free(events); //освобождаем память, выделенную под массив структур для обработки сигналов
    }

    return 0; //выходим без ошибки
}
