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
    int aSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(aSocket < 0)
    {
        write(2, "Error: socket.\n", 15);
        return 1;
    }

    char serverIP[16];
    write(1, "Enter the IP addres of server: ", 31);
    read(0, serverIP, 16);

    int error;
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(7502);
    peer.sin_addr.s_addr = inet_addr(serverIP);

    error = connect(aSocket, (struct sockaddr *)&peer, sizeof(peer));
    if(error)
    {
        write(2, "Error: connect.\n", 16);
        return 1;
    }

    bool exit = false;
    char buf[MAXSTR] = {0};

    while(!exit)
    {
        write(1, "<< ", 3);
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
        else
        {
            memset(buf, 0, strlen(buf));

            write(1, ">> ", 3);
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
            }
        }
    }

    return 0;
}
