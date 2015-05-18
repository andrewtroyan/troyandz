#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

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
    local.sin_port = htons(7500);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    error = bind(listenSocket, (struct sockaddr *)&local, sizeof(local));
    if(error)
    {
        write(2, "Error: bind.\n", 13);
        return 1;
    }

    error = listen(listenSocket, 5); //5 - одновременно подключаемых устройств
    if(error)
    {
        write(2, "Error: listen.\n", 15);
        return 1;
    }

    int aSocket = accept(listenSocket, NULL, NULL); //2 и 3 параметры - определенная структура и длина
    if(aSocket < 0)
    {
        write(2, "Error: accept.\n", 15);
        return 1;
    }

    char buf[3];
    error = read(aSocket, buf, 3);
    if(error <= 0)
    {
        write(2, "Error: read.\n", 13);
        return 1;
    }

    write(1, buf, 3);
    write(1, "\n", 1);

    error = write(aSocket, "456", 3);
    if(error <= 0)
    {
        write(2, "Error: write.\n", 14);
        return 1;
    }

    return 0;
}
