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

    while(1)
    {
        if(read(thrInfo.socket, &sockInfo, sizeof(sockInfo)) > 0)
        {
            if(strlen(sockInfo.name) && strlen(sockInfo.message))
            {
                refresh();
                curs_set(0);
                wclear(thrInfo.listOfWindows[2]);
                wprintw(thrInfo.listOfWindows[1], "%s: %s\n", sockInfo.name, sockInfo.message);
                wprintw(thrInfo.listOfWindows[2], "Users online: %d", sockInfo.amountOfOnline);
                wrefresh(thrInfo.listOfWindows[1]);
                wrefresh(thrInfo.listOfWindows[2]);
                wrefresh(thrInfo.listOfWindows[3]);
                curs_set(1);
            }
            else if(!strcmp(sockInfo.message, "--exit"))
            {
                close(thrInfo.socket);
                deleteWindows(&(thrInfo.listOfWindows));
                fprintf(stderr, "Server is not available.\n");
                exit(1);
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


