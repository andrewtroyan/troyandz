#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSTR 1024

int main()
{
    int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(listenSocket < 0)
    {
        write(2, "Error: socket.\n", 15);
        return 1;
    }

    int error;
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(7501);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    error = bind(listenSocket, (struct sockaddr *)&local, sizeof(local));
    if(error)
    {
        write(2, "Error: bind.\n", 13);
        return 1;
    }

    error = listen(listenSocket, 5);
    if(error)
    {
        write(2, "Error: listen.\n", 15);
        return 1;
    }

    int aSocket = accept(listenSocket, NULL, NULL);
    if(aSocket < 0)
    {
        write(2, "Error: accept.\n", 15);
        return 1;
    }

    bool exit = false;
    char buf[MAXSTR] = {0};

    while(!exit)
    {
        write(1, ">> ", 3);
        memset(buf, 0, strlen(buf));

        error = read(aSocket, buf, MAXSTR);
        if(error <= 0)
        {
            write(2, "Error: read.\n", 13);
            return 1;
        }
        else if(!strcmp(buf, "exit\n") || !strcmp(buf, "exit.\n") || !strcmp(buf, "Exit\n") || !strcmp(buf, "Exit.\n"))
        {
            write(1, "The partner has ended the conversation.\n", 40);
            exit = true;
        }
        else
        {
            write(1, buf, strlen(buf));

            write(1, "<< ", 3);
            memset(buf, 0, strlen(buf));
            read(0, buf, MAXSTR);

            error = write(aSocket, buf, strlen(buf));
            if(error <= 0)
            {
                write(2, "Error: write.\n", 14);
                return 1;
            }
            else if(!strcmp(buf, "exit\n") || !strcmp(buf, "exit.\n") || !strcmp(buf, "Exit\n") || !strcmp(buf, "Exit.\n"))
            {
                exit = true;
            }
        }
    }

    return 0;
}
