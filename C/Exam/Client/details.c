#include "details.h"

int setWindows(WINDOW ***wins, int rows, int cols)
{
    *wins = (WINDOW **)malloc(4 * sizeof(WINDOW *));
    if(!wins)
    {
        fprintf(stderr, "malloc() error.\n");
        return 1;
    }

    (*wins)[0] = NULL;
    (*wins)[1] = NULL;
    (*wins)[2] = NULL;
    (*wins)[3] = NULL;

    initialiseProgram();
    refresh();

    (*wins)[0] = newwin(1, cols, 0, 0);
    (*wins)[1] = newwin(rows - 5, cols, 1, 0);
    (*wins)[2] = newwin(1, cols, rows - 4, 0);
    (*wins)[3] = newwin(3, cols, rows - 3, 0);

    if(!(*wins)[0] || !(*wins)[1] || !(*wins)[2] || !(*wins)[3])
    {
        fprintf(stderr, "newwin() error.\n");
        return 1;
    }

    scrollok((*wins)[1], true); //включаем возможность прокрутки экрана

    wbkgd((*wins)[0], A_REVERSE);
    wbkgd((*wins)[2], A_REVERSE);

    wprintw((*wins)[0], "Multiuser chat (for exit send \"--exit\"):");

    wrefresh((*wins)[0]);
    wrefresh((*wins)[1]);
    wrefresh((*wins)[2]);
    wrefresh((*wins)[3]);

    return 0;
}

void deleteWindows(WINDOW ***wins)
{
    delwin((*wins)[0]);
    delwin((*wins)[1]);
    delwin((*wins)[2]);
    delwin((*wins)[3]);
    endwin();
    free(*wins);
    *wins = NULL;
}

void *readFromServer(void *arg)
{
    ThreadInfo thrInfo = *(ThreadInfo *)arg;
    SocketInfo sockInfo;
    int firstMessage = 1;

    while(1)
    {
        if(read(thrInfo.socket, &sockInfo, sizeof(sockInfo)) > 0)
        {
            if(strlen(sockInfo.name) && strlen(sockInfo.message))
            {
                refresh();
                curs_set(0);

                if(firstMessage)
                {
                    wprintw(thrInfo.listOfWindows[1], "%s: %s", sockInfo.name, sockInfo.message);
                    firstMessage = 0;
                }
                else
                    wprintw(thrInfo.listOfWindows[1], "\n%s: %s", sockInfo.name, sockInfo.message);
//84 и 85 строки пишем для того, чтобы в нашем окне для набора текста был виден курсор
                wclear(thrInfo.listOfWindows[2]);
                wprintw(thrInfo.listOfWindows[2], "Users online: %d", sockInfo.amountOfOnline);
                wrefresh(thrInfo.listOfWindows[1]);
                wrefresh(thrInfo.listOfWindows[2]);
                wrefresh(thrInfo.listOfWindows[3]);
                curs_set(1);
            }
            else if(!strcmp(sockInfo.message, "--exit")) //если сервер нам прислал команду "--exit", то он неожиданно завершил работу
            {
                close(thrInfo.socket);
                deleteWindows(&(thrInfo.listOfWindows));
                fprintf(stderr, "Server is not available.\n"); //выводим сообщение
                exit(1); //выходим с ошибкой
            }
            else
            {
                refresh();
                curs_set(0);
                wclear(thrInfo.listOfWindows[2]);
                wprintw(thrInfo.listOfWindows[2], "Users online: %d", sockInfo.amountOfOnline);
                wrefresh(thrInfo.listOfWindows[2]);
                wrefresh(thrInfo.listOfWindows[3]);
                curs_set(1);
            }
        }
    }
    return NULL;
}

void sigHandler(int arg)
{
    runCode = sig;
}

int setSigAction(void *arg, void (*func)(int arg))
{
    struct sigaction *act = (struct sigaction *)arg;
    sigemptyset(&(act->sa_mask));
    act->sa_flags = 0;
    act->sa_handler = func;

    if(sigaction(SIGHUP, act, NULL) == -1 || sigaction(SIGINT, act, NULL) == -1)
    {
        fprintf (stderr, "sigaction() error.\n");
        return 1;
    }
    return 0;
}

void setSocketInfo(SocketInfo *info, char *name, char *message, int amountOfOnline)
{
    strcpy(info->name, name);
    strcpy(info->message, message);
    info->amountOfOnline = amountOfOnline;
}

void setThrInfo(ThreadInfo *info, WINDOW **wins, int socket, char *name)
{
    info->listOfWindows = wins;
    info->socket = socket;
    strcpy(info->name, name);
}

void setAddr(void *addrStruct, short sinFamily, int sinPort, char *ip)
{
    struct sockaddr_in *temp = (struct sockaddr_in *)addrStruct;
    temp->sin_family = sinFamily;
    temp->sin_port = htons(sinPort);
    temp->sin_addr.s_addr = inet_addr(ip);
}

int setSocket(int *clientSocket)
{
    *clientSocket = socket(AF_INET, SOCK_STREAM, 0); //создаем сокет
    if(*clientSocket < 0)
    {
        fprintf(stderr, "socket() error.\n");
        return 1;
    }

    if(fcntl(*clientSocket, F_SETFL, O_NONBLOCK, 1) == -1) //делаем этот сокет неблокирующим
    {
        fprintf(stderr, "Failed to set non-block mode.\n");
        close(*clientSocket);
        return 1;
    }

    return 0;
}

int connectSocket(int *clientSocket, void *peer)
{
    int error = 1;
//коннектимся к серверу
//так как наш сокет неблокирующий, вводим функцию connect в цикл для того, чтобы мы наверняка подключились
    for(int i = 0; i < 1000 && error; ++i)
        error = connect(*clientSocket, (struct sockaddr *)peer, sizeof(struct sockaddr_in));

    if(error)
    {
        fprintf(stderr, "Can't connect.\n");
        close(*clientSocket);
        return 1;
    }
    return 0;
}








